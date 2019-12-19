#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3f3f3f3f3f3f3f3f;
const int maxn = 1e4 + 5;
const int maxm = 1e5 + 5;

int p[maxn], w[maxn];
long long dp[(int)1e5 + 10];

int main()
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        int W = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", p + i, w + i);
            W = max(W, w[i]);
        }
        W = m + W;
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = w[i]; j <= W; j++)
            {
                dp[j] = min(dp[j], dp[j - w[i]] + p[i]);
            }
        }
        long long answ = 0, ansp = INF;
        for (int i = W; i >= m; i--)
        {
            if (dp[i] < INF && dp[i] < ansp)
            {
                ansp = dp[i];
                answ = i;
            }
        }
        printf("%lld %lld\n", ansp, answ);
    }
    return 0;
}