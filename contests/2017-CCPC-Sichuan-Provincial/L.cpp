#include <iostream>

using namespace std;

const int N = 1e5 + 7, mod = 1e9 + 7;
const __int128 inv6 = 166666668;

__int128 arr[N], sum[N], sum2[N], sum3[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            long long k;
            scanf("%lld", &k);
            arr[i] = k;
            sum[i] = (sum[i - 1] + arr[i]) % mod;
            sum2[i] = (sum2[i - 1] + arr[i] * arr[i] % mod) % mod;
            sum3[i] = (sum3[i - 1] + arr[i] * arr[i] * arr[i] % mod) % mod;
        }
        if (n < 4)
        {
            puts("0");
            continue;
        }
        __int128 ans = 0;
        for (int i = n; i >= 4; i--)
        {
            __int128 tmp = (sum[i - 1] * sum[i - 1] * sum[i - 1] % mod - 3 * sum2[i - 1] * sum[i - 1] % mod + 2 * sum3[i - 1] % mod + mod) % mod;
            tmp = tmp * inv6 * arr[i] % mod;
            ans = (ans + tmp) % mod;
        }
        printf("%lld\n", (long long)ans % mod);
    }
    return 0;
}