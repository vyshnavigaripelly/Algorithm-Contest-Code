#include <iostream>
#include <cstring>
#include <bitset>

using namespace std;

const int N = 507;

struct node
{
    int next, to;
} edge[N * N];

bitset<307> sit[N];
int color[N], vis[N], head[N];
int n, m, q, cnt;

void add(int u, int v)
{
    edge[cnt].next = head[u], edge[cnt].to = v;
    head[u] = cnt++;
}

void dfs(int u)
{
    sit[u].reset();
    vis[u] = 1;
    sit[u][u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!color[v])
        {
            if (!vis[v])
            {
                dfs(v);
            }
            sit[u] |= sit[v];
        }
    }
}

int main()
{
    while (~scanf("%d%d%d", &n, &m, &q))
    {
        for (int i = 1; i <= n; i++)
            sit[i].reset();
        cnt = 0;
        memset(head, -1, sizeof(head));
        memset(color, 0, sizeof(color));
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            add(u, v);
        }
        while (q--)
        {
            int u;
            scanf("%d", &u);
            color[u] ^= 1;
            int ans = 0;
            memset(vis, 0, sizeof(vis));
            for (int i = 1; i <= n; i++)
            {
                if (!color[i])
                {
                    if (!vis[i])
                    {
                        dfs(i);
                    }
                    ans += sit[i].count() - 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}