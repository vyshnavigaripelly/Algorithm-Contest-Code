#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 660;

int s;

double cost[MAXN][MAXN]; // 耗费矩阵，标号从0开始，0~n-1
double ans[MAXN * MAXN];

bool vis[MAXN];
double lowc[MAXN];

double Prim(int n)
{
    int cnt = 0;
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
        ans[cnt++] = minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    sort(ans, ans + cnt);
    return ans[cnt - s];
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(cost, 0x3f, sizeof(cost));
        int n, p[660][2];
        cin >> s >> n;
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
                cost[i][j] = cost[j][i] = dist;
            }
        }
        printf("%.2f\n", Prim(n));
    }
    return 0;
}