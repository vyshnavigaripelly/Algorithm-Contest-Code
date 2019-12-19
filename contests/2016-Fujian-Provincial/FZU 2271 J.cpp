#include <iostream>
#include <cstring>
#include <map>

using namespace std;

struct node
{
    int u, v, w;
    node(int u, int v, int w) : u(u), v(v), w(w) {}
    node() {}
} edge[40007];

int mp[107][107], rk[107][107];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m;
        memset(mp, 0x3f, sizeof(mp));
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            mp[i][i] = 0;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            if (mp[u][v] != 0x3f3f3f3f)
                ans++;
            mp[u][v] = min(mp[u][v], w);
            mp[v][u] = mp[u][v];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                rk[i][j] = mp[i][j];
            }
        }
        for (int k = 1; k <= n; k++)
        {
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= n; j++)
                {
                    mp[i][j] = min(mp[i][j], mp[i][k] + mp[k][j]);
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (rk[i][j] == 0x3f3f3f3f)
                    continue;
                for (int k = 1; k <= n; k++)
                {
                    if (i == k || j == k)
                        continue;
                    if (mp[i][j] < rk[i][j] || (mp[i][j] == mp[i][k] + mp[k][j]))
                    {
                        ans++;
                        break;
                    }
                }
            }
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}