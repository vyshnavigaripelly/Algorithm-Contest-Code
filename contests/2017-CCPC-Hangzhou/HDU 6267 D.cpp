#include <iostream>

using namespace std;

const int N = 100007, mod = 998244353;

__int128 a[N], p[N], q[N], mulp[N], mulq[N], invmulq[N], invn;

__int128 qpow(__int128 a, __int128 b, __int128 m = mod)
{
    __int128 ans = 1;
    while (b)
    {
        if (b & 1)
            ans = ans * a % m;
        a = a * a % mod;
        b >>= 1;
    }
    return ans;
}

__int128 inv(__int128 n)
{
    return qpow(n, mod - 2);
}

int main()
{
    __int128 fac = 1;
    mulp[0] = p[0] = 1;
    mulq[0] = q[0] = 1;
    mulp[1] = p[1] = 2;
    mulq[1] = q[1] = 1;
    invmulq[0] = inv(mulq[0]);
    invmulq[1] = inv(mulq[1]);
    for (int i = 2; i < N; i++)
    {
        q[i] = p[i - 1] * i % mod;
        p[i] = (q[i] + fac) % mod;
        mulp[i] = mulp[i - 1] * p[i] % mod;
        mulq[i] = mulq[i - 1] * q[i] % mod;
        invmulq[i] = inv(mulq[i]);
        fac = fac * i % mod;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        invn = inv(n);
        for (int i = 0; i < n; i++)
        {
            long long k;
            scanf("%lld", &k);
            a[i] = k;
        }
        __int128 ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += a[i] * mulp[i] % mod * invmulq[i] % mod * invn % mod;
            ans %= mod;
        }
        printf("%lld\n", (long long)ans);
    }
    return 0;
}