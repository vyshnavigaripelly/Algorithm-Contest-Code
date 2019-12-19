#include <iostream>

using namespace std;

const int mod = 1e9 + 7;
const int N = 3e3 + 7;

long long dp[N][N];

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        for (int i = 0; i <= n + m + 1; i++)
        {
            for (int j = 0; j <= n + m + 1; j++)
            {
                dp[i][j] = 0;
            }
        }
        dp[0][0] = 1;
        for (int i = 1; i <= n + m + 1; i++)
        {
            for (int j = 1; j <= n + m + 1; j++)
            {
                if (i < n || i - n < j)
                {
                    dp[i][j - 1] += dp[i - 1][j - 1];
                    dp[i][j - 1] %= mod;
                }
                if (j < m || j - m < i)
                {
                    dp[i - 1][j] += dp[i - 1][j - 1];
                    dp[i - 1][j] %= mod;
                }
            }
        }
        cout << dp[n + m][n + m] << endl;
    }
    return 0;
}