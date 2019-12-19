#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 110;

double cost[MAXN][MAXN]; // 耗费矩阵，标号从0开始，0~n-1

bool vis[MAXN];
double lowc[MAXN];

double Prim(int n)
{
    double ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        double minc = INF;
        int p = -1;
        for (int j = 0; j < n; j++)
            if (!vis[j] && minc > lowc[j])
            {
                minc = lowc[j];
                p = j;
            }
        if (minc == INF)
            return -1; // 原图不连通
        ans += minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(cost, 0x3f, sizeof(cost));
        int n, p[110][2];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i][0] >> p[i][1];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    cost[i][j] = 0;
                    continue;
                }
                double dist = sqrt(pow(p[i][0] - p[j][0], 2) + pow(p[i][1] - p[j][1], 2));
                if (dist >= 10 && dist <= 1000)
                {
                    cost[i][j] = cost[j][i] = dist;
                }
                else
                {
                    cost[i][j] = cost[j][i] = INF;
                }
            }
        }
        double ans = Prim(n);
        if (ans == -1)
        {
            puts("oh!");
        }
        else
        {
            printf("%.1f\n", ans * 100);
        }
    }
    return 0;
}