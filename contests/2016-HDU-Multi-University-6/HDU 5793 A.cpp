#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 7;

long long fac[maxn + 5], invfac[maxn + 5];

long long qpow(long long x, long long n, long long m = mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % m;
        x = x * x % m;
        n >>= 1;
    }
    return s % m;
}

long long inv(long long n)
{
    return qpow(n, mod - 2);
}

void init()
{
    fac[0] = 1;
    for (long long i = 1; i <= maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    invfac[maxn] = qpow(fac[maxn], mod - 2);
    for (long long i = maxn - 1; i >= 0; i--)
        invfac[i] = invfac[i + 1] * (i + 1) % mod;
}

long long C(long long n, long long m)
{
    if (m > n)
        return 0;
    if (m == n || m == 0)
        return 1;
    return fac[n] * invfac[n - m] % mod * invfac[m] % mod;
}

vector<long long> getk(long long x, long long base, long long num)
{
    vector<long long> ans;
    while (num--)
    {
        ans.insert(ans.begin(), x % base);
        x /= base;
    }
    return ans;
}

long long table(long long n, long long m)
{
    long long sum = 0;
    for (long long i = 0; i < qpow(n + 1, m); i++)
    {
        auto k = getk(i, n + 1, m);
        long long tmp = 1;
        for (int j = 1; j < k.size(); j++)
        {
            tmp *= C(k[j], k[j - 1]);
        }
        sum += tmp;
    }
    return sum;
}

void maketable()
{
    init();
    for (int n = 0; n <= 5; n++)
    {
        for (int m = 2; m <= 5; m++)
        {
            printf("%lld ", table(n, m));
        }
        puts("");
    }
}

int main()
{
    // maketable();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, m;
        scanf("%lld %lld", &n, &m);
        if (n == 0)
        {
            printf("1\n");
            continue;
        }
        long long k = inv(m - 1);
        long long ans = (qpow(m, n - 1) * ((m + 1 + k) % mod) % mod - k + mod) % mod;
        printf("%lld\n", ans);
    }
    return 0;
}