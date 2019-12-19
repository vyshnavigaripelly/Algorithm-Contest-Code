#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
const int mod = 1e9 + 7;

long long f[N];

long long qpow(long long a, long long b, long long mod = mod)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res % mod;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        f[1] = qpow(2, k);
        f[2] = qpow(2, k) * (qpow(2, k) - 1) % mod;
        for (int i = 3; i <= n; i++)
        {
            f[i] = f[i - 2] + f[1] * (f[1] - 2) % mod * qpow(f[1] - 1, i - 2) % mod;
            f[i] %= mod;
        }
        printf("%lld\n", f[n]);
    }
    return 0;
}
