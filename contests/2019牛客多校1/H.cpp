#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int maxd = 63;
const int N = 1e5 + 7;
const long long mod = 1e9 + 7;

long long fir[N], sec[N];

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
    return s;
}

struct LinearBasis
{
    static const int maxn = 65;
    bool zero;
    int cnt, tot;
    long long d[maxn], p[maxn];

    void init()
    {
        cnt = zero = tot = 0;
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
    }

    bool insert(long long val)
    {
        for (int i = maxd; i >= 0; i--)
        {
            if (val & (1ll << i))
            {
                if (!d[i])
                {
                    d[i] = val;
                    tot++;
                    break;
                }
                val ^= d[i];
            }
        }
        if (!val)
            zero = 1;
        return val;
    }

    long long query_max()
    {
        long long res = 0;
        for (int i = maxd; i >= 0; i--)
            res = max(res, res ^ d[i]);
        return res;
    }

    long long query_min()
    {
        if (zero)
            return 0;
        for (int i = 0; i <= maxd; i++)
            if (d[i])
                return d[i];
        return 0;
    }

    void rebuild()
    {
        for (int i = maxd; i >= 0; i--)
            for (int j = i - 1; j >= 0; j--)
                if (d[i] & (1ll << j))
                    d[i] ^= d[j];
        for (int i = 0; i <= maxd; i++)
            if (d[i])
                p[cnt++] = d[i];
    }

    long long kth(long long k)
    {
        long long res = 0;
        if (zero)
            k--;
        if (k >= (1ll << cnt))
            return -1;
        for (int i = maxd; i >= 0; i--)
            if (k & (1 << i))
                res ^= p[i];
        return res;
    }
};

LinearBasis merge(const LinearBasis &a, const LinearBasis &b)
{
    LinearBasis res = a;
    for (int i = maxd; i >= 0; i++)
        if (b.d[i])
            res.insert(b.d[i]);
    return res;
}

LinearBasis arr, brr, crr;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        int sum = 0, tmp = 0;
        arr.init();
        brr.init();
        crr.init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &fir[i]);
            if (arr.insert(fir[i]))
            {
                sec[tmp++] = fir[i];
                sum++;
            }
            else
            {
                brr.insert(fir[i]);
            }
        }
        long long ans = qpow(2, n - sum - 1) * (n - sum) % mod;
        for (int i = 0; i < arr.tot; i++)
        {
            crr = brr;
            for (int j = 0; j < arr.tot; j++)
            {
                if (i == j)
                    continue;
                crr.insert(sec[j]);
            }
            if (!crr.insert(sec[i]))
                (ans += qpow(2, n - sum - 1)) %= mod;
        }
        printf("%lld\n", ans);
    }
    return 0;
}