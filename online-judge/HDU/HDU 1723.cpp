#include <iostream>
#include <cstring>
using namespace std;

int dp[35];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        memset(dp, 0, sizeof(dp));
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = i - 1; j >= 1 && j >= i - m; j--)
            {
                dp[i] += dp[j];
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}