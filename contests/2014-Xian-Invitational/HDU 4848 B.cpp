#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, minans;
int d[37][37], dead[37], vis[37];

void dfs(int u, int cost, int sum, int cnt)
{
    if (cnt == n)
    {
        minans = min(minans, sum);
        return;
    }
    if (sum >= minans)
        return;
    for (int i = 2; i <= n; i++)
    {
        int w = cost + d[u][i];
        if (i != u && !vis[i])
        {
            int flag = 1;
            for (int j = 2; j <= n; j++)
            {
                if (!vis[j] && w > dead[j])
                    flag = 0;
            }
            if (flag)
            {
                vis[i] = 1;
                dfs(i, w, sum + (n - cnt) * d[u][i], cnt + 1);
                vis[i] = 0;
            }
        }
    }
}

int main()
{
    while (~scanf("%d", &n))
    {
        minans = 0x3f3f3f3f;
        memset(vis, 0, sizeof(vis));
        vis[1] = 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                scanf("%d", &d[i][j]);
            }
        }
        for (int i = 2; i <= n; i++)
        {
            scanf("%d", &dead[i]);
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        dfs(1, 0, 0, 1);
        if (minans == 0x3f3f3f3f)
            puts("-1");
        else
            printf("%d\n", minans);
    }
    return 0;
}
