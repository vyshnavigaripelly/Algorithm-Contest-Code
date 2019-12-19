#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int N = 3e5 + 7;
const int mod = 998244353;

struct node
{
    int next, to;
    bool used;
} edge[N << 2], tree[N << 2];

queue<int> q;
long long ans;
int t, n, m, cnt;
int vis[N], head[N], head1[N], d[N], rk[N << 2], dist[N], f[N][20];

void add(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].used = 0;
    rk[cnt] = u;
    head[u] = cnt++;

    edge[cnt].to = u;
    edge[cnt].next = head[v];
    edge[cnt].used = 0;
    rk[cnt] = v;
    head[v] = cnt++;
}

void addt(int u, int v)
{
    tree[cnt].to = v;
    tree[cnt].next = head1[u];
    head1[u] = cnt++;

    tree[cnt].to = u;
    tree[cnt].next = head1[v];
    head1[v] = cnt++;
}

long long pow_m(long long x, long long y)
{
    long long res = 1;
    while (y)
    {
        if (y & 1)
        {
            res = res * x % mod;
        }
        x = x * x % mod;
        y >>= 1;
    }
    return res;
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (vis[v])
            continue;
        vis[v] = 1;
        edge[i].used = 1;
        edge[i ^ 1].used = 1;
        addt(u, v);
        dfs(v);
    }
}

void bfs(int s)
{
    q.push(s);
    d[s] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head1[x]; ~i; i = tree[i].next)
        {
            int y = tree[i].to;
            if (d[y])
                continue;
            d[y] = d[x] + 1;
            dist[y] = dist[x] + 1;
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
            {
                f[y][j] = f[f[y][j - 1]][j - 1];
            }
            q.push(y);
        }
    }
}

int lca(int x, int y)
{
    if (d[x] > d[y])
    {
        swap(x, y);
    }
    for (int i = t; i >= 0; i--)
    {
        if (d[f[y][i]] >= d[x])
            y = f[y][i];
    }
    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i], y = f[y][i];
        }
    }
    return f[x][0];
}

int main()
{
    ans = 1;
    memset(head, -1, sizeof(head));
    memset(head1, -1, sizeof(head1));
    scanf("%d%d", &n, &m);
    t = (int)(log(n) / log(2)) + 1;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        add(u, v);
    }
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            dfs(i);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            bfs(i);
        }
    }
    int tot = 0;
    for (int i = 0; i < m * 2; i += 2)
    {
        if (!edge[i].used)
        {
            int u = rk[i], v = edge[i].to;
            int siz = dist[u] + dist[v] - 2 * dist[lca(u, v)];
            siz++;
            ans = (ans * (pow_m(2, siz) - 1)) % mod;
            tot += siz;
        }
    }
    ans = (ans * pow_m(2, m - tot)) % mod;
    printf("%lld\n", ans % mod);
    return 0;
}