#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct school
{
    int cost;
    double p;
} arr[10007];

double dp[10007];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        memset(arr, 0, sizeof(arr));
        for (int i = 1; i <= m; i++)
        {
            cin >> arr[i].cost >> arr[i].p;
        }
        for (int i = 0; i <= n; i++)
        {
            dp[i] = 1;
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = n; j >= arr[i].cost; j--)
            {
                dp[j] = min(dp[j], dp[j - arr[i].cost] * (1 - arr[i].p));
            }
        }
        printf("%.1lf%%\n", 100 * (1 - dp[n]));
    }
    return 0;
}