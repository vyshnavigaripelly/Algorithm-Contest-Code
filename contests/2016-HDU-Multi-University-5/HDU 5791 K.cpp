#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int mod = 1000000007;

long long dp[1007][1007], a[1007], b[1007];

int main()
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%lld", &b[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (a[i] == b[j])
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + 1) % mod;
                }
                else
                {
                    dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + mod) % mod;
                }
            }
        }
        printf("%lld\n", dp[n][m]);
    }
    return 0;
}