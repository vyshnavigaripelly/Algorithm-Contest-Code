#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;

long long FastPow(long long x, long long n, long long mod = mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s;
}

long long inv(long long n)
{
    return FastPow(n, mod - 2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        long long ans = 0;
        ans += FastPow(n, 4);
        ans %= mod;
        ans += 6 * FastPow(n, 3);
        ans %= mod;
        ans += 11 * FastPow(n, 2);
        ans %= mod;
        ans += 6 * n;
        ans %= mod;
        ans *= inv(24);
        ans %= mod;
        printf("%lld\n", ans);
    }
    return 0;
}