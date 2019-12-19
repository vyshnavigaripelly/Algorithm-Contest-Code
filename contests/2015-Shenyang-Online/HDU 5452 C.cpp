#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <queue>
#include <vector>

using namespace std;

const int N = 1e5 + 7;

struct
{
    int next;
    int to;
} edge[N << 1];

queue<int> q;
int head[N], f[N][20], d[N], arr[N], SIZE[N];
int n, t, m, cnt;

void add(int u, int v)
{
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt++;
}

void bfs()
{
    q.push(1);
    d[1] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (d[v])
                continue;
            d[v] = d[u] + 1;
            f[v][0] = u;
            for (int j = 1; j <= t; j++)
            {
                f[v][j] = f[f[v][j - 1]][j - 1];
            }
            q.push(v);
        }
    }
}

int lca(int x, int y)
{
    if (d[x] > d[y])
        swap(x, y);
    for (int i = t; i >= 0; i--)
    {
        if (d[f[y][i]] >= d[x])
        {
            y = f[y][i];
        }
    }
    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
        {
            x = f[x][i];
            y = f[y][i];
        }
    }
    return f[x][0];
}

void dfs(int u, int fa)
{
    SIZE[u] = arr[u];
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        dfs(v, u);
        SIZE[u] += SIZE[v];
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(head, -1, sizeof(head));
        memset(d, 0, sizeof(d));
        memset(arr, 0, sizeof(arr));
        memset(f, 0, sizeof(f));
        cnt = 0;
        scanf("%d %d", &n, &m);
        t = (int)(log(n) / log(2)) + 1;
        for (int i = 1; i < n; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
            add(v, u);
        }
        bfs();
        for (int i = 0; i < m - n + 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            arr[u]++, arr[v]++;
            arr[lca(u, v)] -= 2;
        }
        dfs(1, -1);
        int ans = 0x3f3f3f3f;
        for (int i = 2; i <= n; i++)
        {
            ans = min(ans, SIZE[i]);
        }
        printf("Case #%d: %d\n", cas, ans + 1);
    }
    return 0;
}