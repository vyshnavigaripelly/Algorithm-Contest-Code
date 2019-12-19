#include <iostream>

using namespace std;

const int mod = 998244353;

long long qpow(long long a, long long b, long long m = mod)
{
    long long ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

long long inv(int n)
{
    return qpow(n, mod - 2);
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long ans = 1;
        while (n--)
        {
            long long p, q;
            scanf("%lld %lld", &p, &q);
            ans = ans * (p + q * (p - 1) % mod) % mod * inv(p) % mod * qpow(p, q) % mod;
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}