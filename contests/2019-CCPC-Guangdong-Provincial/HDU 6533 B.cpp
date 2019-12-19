#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[400007], mod;

long long qpow(long long x, long long n)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x;
        x = x * x;
        n >>= 1;
    }
    return s;
}

int main()
{
    long long k, m, n;
    while (~scanf("%lld %lld %lld %lld", &k, &m, &n, &mod))
    {
        for (int i = 1; i <= k; i++)
        {
            scanf("%lld", &arr[i]);
        }
        sort(arr + 1, arr + 1 + k);
        long long l = 1, r = n;
        long long ans = 0;
        for (int i = 1; i <= m - 1; i++)
        {
            for (int j = l; j <= r; j++)
            {
                ans += arr[j] * 1LL * ((1 - qpow(n, m - i)) / (1LL - n));
                ans %= mod;
            }
            l = r + 1;
            r = qpow(n, i + 1) + r;
        }
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}