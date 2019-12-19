#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n, m, e;
int map[150][150];
int link[150];
int vis[150];

int solve(int x)
{
    for (int i = 1; i <= m; i++)
    {
        if (!vis[i] && map[x][i])
        {
            vis[i] = 1;
            if (link[i] == -1 || solve(link[i]))
            {
                link[i] = x;
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(map, 1, sizeof(map));
        scanf("%d %d %d", &n, &m, &e);
        while (e--)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            map[u][v] = 0;
        }
        memset(link, -1, sizeof(link));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            memset(vis, 0, sizeof(vis));
            if (solve(i))
            {
                ans++;
            }
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}