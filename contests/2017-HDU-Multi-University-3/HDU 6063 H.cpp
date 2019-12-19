#include <iostream>
#include <cstdio>

using namespace std;

const int mod = 1e9 + 7;

long long fmul(long long a, long long b, long long mod = mod)
{
    long long ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % mod;
        a = a * 2 % mod;
        b >>= 1;
    }
    return ans;
}

long long fpow(long long a, long long b, long long mod = mod)
{
    long long ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = fmul(ans, a);
        a = fmul(a, a);
        b >>= 1;
    }
    return ans;
}

int main()
{
    long long n, m;
    for (int cas = 1; ~scanf("%lld %lld", &n, &m); cas++)
    {
        printf("Case #%d: %lld\n", cas, fpow(n, m));
    }
    return 0;
}