#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct rice
{
    int cost, weight, amount;
} arr[107];

int dp[1007][1007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= m; i++)
        {
            cin >> arr[i].cost >> arr[i].weight >> arr[i].amount;
        }
        for (int i = 1; i <= m + 1; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                for (int k = 0; k <= arr[i].amount && k * arr[i].cost <= j; k++)
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - k * arr[i].cost] + k * arr[i].weight);
                }
            }
        }
        cout << dp[m][n] << endl;
    }
    return 0;
}