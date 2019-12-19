#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
const int N = 5e5 + 7;

int l, r, m, n;
long long arr[N], brr[N], sum[N];

int main()
{
    long long ans = 0;
    while (~scanf("%d%d%d%d", &n, &m, &l, &r))
    {
        memset(sum, 0, sizeof(sum));
        n++, m++, l++, r++;
        for (int i = 1; i <= n; i++)
            scanf("%lld", &arr[i]);
        for (int i = 1; i <= m; i++)
            scanf("%lld", &brr[i]);
        sum[m + 1] = 0;
        for (int i = m; i >= 1; --i)
        {
            sum[i] = (brr[i] + sum[i + 1]) % mod;
        }
        ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int ll = max(0, l - i) + 1;
            int rr = min(m, r - i) + 1;
            if (ll <= rr)
            {
                ans += 1LL * arr[i] * (sum[ll] - sum[rr + 1] + mod) % mod;
                ans = (ans + mod) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}