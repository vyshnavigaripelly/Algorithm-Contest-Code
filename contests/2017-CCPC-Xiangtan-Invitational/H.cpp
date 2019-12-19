#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1e5 + 7;

struct node
{
    int next, to, w;
} tree[N << 1];

int cnt, st, ed, type, t;
int head[N], f[N][20], dep[N];
long long dist[N];
long long maxn;
queue<int> q;

void add(int u, int v, int w)
{
    tree[cnt].next = head[u];
    tree[cnt].to = v;
    tree[cnt].w = w;
    head[u] = cnt++;
}

void dfs(int u, int fa, long long weight)
{
    if (weight > maxn)
    {
        maxn = weight;
        if (type)
            ed = u;
        else
            st = u;
    }
    for (int i = head[u]; ~i; i = tree[i].next)
    {
        int v = tree[i].to, w = tree[i].w;
        if (v == fa)
            continue;
        dfs(v, u, weight + w);
    }
}

void bfs()
{
    q.push(1);
    dep[1] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = tree[i].next)
        {
            int v = tree[i].to;
            if (dep[v])
            {
                continue;
            }
            dep[v] = dep[u] + 1;
            dist[v] = dist[u] + tree[i].w;
            f[v][0] = u;
            for (int j = 1; j <= t; j++)
            {
                f[v][j] = f[f[v][j - 1]][j - 1];
            }
            q.push(v);
        }
    }
}

int lca(int u, int v)
{
    if (dep[u] > dep[v])
    {
        swap(u, v);
    }
    for (int i = t; i >= 0; i--)
    {
        if (dep[f[v][i]] >= dep[u])
        {
            v = f[v][i];
        }
    }
    if (u == v)
        return u;
    for (int i = t; i >= 0; i--)
    {
        if (f[u][i] != f[v][i])
        {
            u = f[u][i], v = f[v][i];
        }
    }
    return f[u][0];
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(head, -1, sizeof(head));
        memset(dep, 0, sizeof(dep));
        cnt = 0;
        t = (int)(log(n) / log(2)) + 1;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        long long ans = 0;
        maxn = -1;
        type = 0;
        dfs(1, -1, 0LL);
        type = 1;
        maxn = -1;
        dfs(st, -1, 0LL);
        ans += maxn;
        bfs();
        for (int i = 1; i <= n; i++)
        {
            if (i == ed || i == st)
            {
                continue;
            }
            ans += max(dist[st] + dist[i] - 2LL * dist[lca(st, i)], dist[ed] + dist[i] - 2LL * dist[lca(ed, i)]);
        }
        cout << ans << endl;
    }
    return 0;
}