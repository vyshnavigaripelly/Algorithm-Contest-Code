#include <cstdio>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

const int mod = 1e9 + 7;

int dp[200010];
int w[200010];

int main()
{
    int t, n, x;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        int m = 0;
        for (int i = 1; i <= n; ++i)
            scanf("%d", &w[i]), m += w[i];
        sort(w + 1, w + 1 + n);
        dp[0] = 1;
        for (int i = 1; i <= n; ++i)
        {
            for (int j = m; j >= w[i]; --j)
            {
                dp[j] = (dp[j] + dp[j - w[i]]) % mod;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= n; ++i)
        {
            int L = ceil((m - 2 * w[i]) / 2.0);
            int R = floor((m - w[i]) / 2.0);
            for (int j = 0; j <= m; ++j)
            {
                if (j >= w[i])
                    dp[j] = (dp[j] - dp[j - w[i]] + mod) % mod;
                if (j >= L && j <= R)
                    ans = (ans + dp[j]) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}