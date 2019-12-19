#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1000000007;

long long fpow(long long x, long long n, long long mod = mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
        {
            s = s * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}

int main()
{
    long long n;
    while (~scanf("%lld", &n))
    {
        long long ans = ((n - 1) % mod * fpow(2, n) % mod + 1) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}