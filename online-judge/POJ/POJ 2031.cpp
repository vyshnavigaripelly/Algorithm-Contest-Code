#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 110;

double cost[MAXN][MAXN];
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
            return -1;
        ans += minc;
        vis[p] = true;
        for (int j = 0; j < n; j++)
            if (!vis[j] && lowc[j] > cost[p][j])
                lowc[j] = cost[p][j];
    }
    return ans;
}

struct cell
{
    double x, y, z, r;
} arr[150];

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        memset(cost, 0x3f, sizeof(cost));
        for (int i = 0; i < n; i++)
        {
            scanf("%lf %lf %lf %lf", &arr[i].x, &arr[i].y, &arr[i].z, &arr[i].r);
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
                double t = sqrt(pow(arr[i].x - arr[j].x, 2) + pow(arr[i].y - arr[j].y, 2) + pow(arr[i].z - arr[j].z, 2));
                double dist = max(t - arr[i].r - arr[j].r, 0.0);
                cost[i][j] = cost[j][i] = dist;
            }
        }
        printf("%.3f\n", Prim(n));
    }
    return 0;
}