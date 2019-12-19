#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const long long mod = 998244353;
const long long maxn = 2e5 + 7;

long long c[maxn + 7], inv[maxn + 7], fac[maxn + 7];

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
    return s % mod;
}

void makeinv()
{
    fac[0] = 1;
    for (long long i = 1; i <= maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    inv[maxn] = FastPow(fac[maxn], mod - 2);
    for (long long i = maxn - 1; i >= 0; i--)
        inv[i] = inv[i + 1] * (i + 1) % mod;
}

long long C(long long n, long long m)
{
    if (m > n)
        return 0;
    if (m == n || m == 0)
        return 1;
    return fac[n] * inv[n - m] % mod * inv[m] % mod;
}

int main()
{
    makeinv();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        long long tmp = min(k / n, m);
        long long ans = 0;
        for (long long i = 0; i <= tmp; i++)
        {
            ans = ans + ((i % 2 == 1 ? -1 : 1) * (C(k + m - 1 - n * i, m - 1) % mod) + mod) % mod * (C(m, i) % mod);
            ans %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}