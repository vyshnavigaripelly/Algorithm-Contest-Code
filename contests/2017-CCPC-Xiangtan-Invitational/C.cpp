#include <bits/stdc++.h>

using namespace std;

const int maxd = 61;
const int N = 55;

struct LinearBasis
{
    static const int maxn = 65;

    bool zero; // 判断序列中是否有0
    int cnt, tot; // tot为d数组长度，cnt为p数组长度
    long long d[maxn], p[maxn]; // d数组放线性基

    void init()
    {
        cnt = zero = tot = 0;
        memset(d, 0, sizeof(d));
        memset(p, 0, sizeof(p));
    }

    bool insert(long long val) // 判断插入是否成功
    {
        for (int i = maxd; i >= 0; i--)
        {
            if (val & (1LL << i))
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

    bool check(long long val) // 判断val是否在线性基内
    {
        for (int i = maxd; i >= 0; i--)
        {
            if (val & (1LL << i))
            {
                if (!d[i])
                    return 1;
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

    void rebuild() // 求第k大前使用
    {
        for (int i = maxd; i >= 0; i--)
            for (int j = i - 1; j >= 0; j--)
                if (d[i] & (1LL << j))
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
        if (k >= (1LL << cnt))
            return -1;
        for (int i = maxd; i >= 0; i--)
            if (k & (1LL << i))
                res ^= p[i];
        return res;
    }

    LinearBasis intersect(const LinearBasis &b)
    {
        LinearBasis res;
        res.init();
        long long f[maxn] = {0}, g[maxn] = {0};
        for (long long i = 0; i <= maxd; i++)
            g[i] = d[i];
        for (long long i = maxd; i >= 0; i--)
        {
            auto x = b.d[i], y = 1LL << i;
            for (int j = maxd; j >= 0; j--)
            {
                if (x >> j & 1)
                {
                    if (g[j])
                    {
                        x ^= g[j], y ^= f[j];
                    }
                    else
                    {
                        g[j] = x, f[j] = y;
                        break;
                    }
                }
            }
            if (x == 0)
            {
                long long sum = 0;
                for (long long j = maxd; j >= 0; j--)
                    if (y >> j & 1)
                        sum ^= b.d[j];
                res.insert(sum);
            }
        }
        return res;
    }
};

LinearBasis arr, brr, crr;
long long fir[N], sec[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        arr.init(), brr.init(), crr.init();
        for (int i = 1; i <= n; i++)
        {
            long long q;
            scanf("%lld", &q);
            arr.insert(q);
        }
        for (int i = 1; i <= n; i++)
        {
            long long q;
            scanf("%lld", &q);
            brr.insert(q);
        }
        long long ans = 0;

        crr = arr.intersect(brr);
        ans = 1LL << (crr.tot);
        printf("%lld\n", ans);
    }
}