#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int arr[2007], dp[2007][2007];

int main()
{
    int n, k;
    while (cin >> n >> k)
    {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0x3f, sizeof(dp));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        sort(arr + 1, arr + 1 + n);
        for (int i = 0; i <= n; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j * 2 <= i; j++)
            {
                dp[i][j] = min(dp[i - 2][j - 1] + (int)pow(arr[i] - arr[i - 1], 2), // 选第i和i-1件组成第j对
                               dp[i - 1][j]); // 不选
            }
        }
        cout << dp[n][k] << endl;
    }
    return 0;
}