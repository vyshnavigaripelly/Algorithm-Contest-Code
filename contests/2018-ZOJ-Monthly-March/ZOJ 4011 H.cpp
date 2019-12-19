#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

int dp[2007][2007];

int main()
{
    for (int i = 1; i <= 2005; i++)
    {
        dp[1][i] = 1;
    }
    for (int i = 1; i < 2005; i++)
    {
        for (int j = 1; j <= 2005; j++)
        {
            for (int k = j; k <= 2005; k += j)
            {
                dp[i + 1][k] = (dp[i + 1][k] + dp[i][j]) % mod;
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            ans = (ans + dp[m][i]) % mod;
        }
        cout << ans << endl;
    }
    return 0;
}