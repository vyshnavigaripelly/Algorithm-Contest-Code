#include <iostream>
#include <cstring>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1100;

int cost[MAXN][MAXN]; // 耗费矩阵，标号从0开始，0~n-1
int arr[MAXN];

bool vis[MAXN];
int lowc[MAXN];

int Prim(int n)
{
    int ans = 0;
    memset(vis, false, sizeof(vis));
    vis[0] = true;
    for (int i = 1; i < n; i++)
        lowc[i] = cost[0][i];
    for (int i = 1; i < n; i++)
    {
        int minc = INF;
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
        memset(arr, 0, sizeof(arr));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cin >> cost[i][j];
                if (i != j)
                {
                    cost[i][j] += arr[i] + arr[j];
                }
            }
        }
        cout << Prim(n) << endl;
    }
    return 0;
}