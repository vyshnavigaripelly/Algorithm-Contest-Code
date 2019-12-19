#include <iostream>

using namespace std;

const int mod = 998244353;

long long qpow(long long a, long long b = mod - 2, long long m = mod)
{
    long long s = 1;
    while (b)
    {
        if (b & 1)
            s = s * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return s % m;
}

int main()
{
    long long nn;
    scanf("%lld", &nn);
    __int128 n = nn;
    __int128 ans = 0, i;
    for (i = 2; i * i <= n; i++)
    {
        __int128 cnt = 1, last = 1, now = 2, tmp = 0;
        __int128 pownow = i * i, powlast = i;
        while (pownow <= n)
        {
            tmp = (tmp + cnt * (pownow - powlast + mod) % mod) % mod;
            now++, cnt++, last++;
            pownow *= i;
            powlast *= i;
        }
        if (powlast < n)
        {
            tmp = (tmp + cnt * (n - powlast + 1 + mod) % mod) % mod;
        }
        ans = (ans + tmp * i % mod) % mod;
    }
    __int128 a = i + n, b = n - i + 1;
    __int128 tmp1 = n * a % mod * b % mod * qpow(2) % mod;
    __int128 tmp2 = n * (n + 1) % mod * (2 * n + 1) % mod * qpow(6) % mod;
    __int128 tmp3 = (i - 1) * i % mod * (2 * (i - 1) + 1) % mod * qpow(6) % mod;
    __int128 tmp4 = n * (n + 1) % mod * qpow(2) % mod;
    __int128 tmp5 = (i - 1) * i % mod * qpow(2) % mod;
    ans = (ans + tmp1 - (tmp2 - tmp3) + (tmp4 - tmp5)) % mod;
    ans = (ans % mod + mod) % mod;
    printf("%lld\n", (long long)ans);
    return 0;
}