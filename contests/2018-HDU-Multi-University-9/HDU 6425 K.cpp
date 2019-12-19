#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 998244353;

long long qpow(long long x, long long n)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a, b, c, d;
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        long long ans = qpow(2, a) * ((qpow(2, b) + (qpow(2, c) - 1 + mod) % mod * (1 + b + d) % mod + d) % mod);
        printf("%lld\n", ans % mod);
    }
    return 0;
}