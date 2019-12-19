#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 5e4 + 7;

vector<long long> arr[N];

struct LinearBasis
{
    static const int maxd = 32;
    static const int maxn = 35;

    bool zero;
    int tot;
    long long d[maxn];

    void init()
    {
        zero = tot = 0;
        memset(d, 0, sizeof(d));
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
                {
                    return 1;
                }
                val ^= d[i];
            }
        }
        if (!val)
            zero = 1;
        return val;
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

struct SegTree
{
    int l, r;
    LinearBasis lb;
} tr[N << 2];

void pushup(int root)
{
    tr[root].lb = tr[lson].lb.intersect(tr[rson].lb);
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        for (auto i : arr[l])
        {
            tr[root].lb.insert(i);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

int query(int root, int l, int r, long long val)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].lb.check(val);
    int mid = (tr[root].l + tr[root].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans |= query(lson, l, r, val);
    if (r > mid)
        ans |= query(rson, l, r, val);
    return ans;
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int sz;
        scanf("%d", &sz);
        while (sz--)
        {
            long long k;
            scanf("%lld", &k);
            arr[i].push_back(k);
        }
    }
    build(1, 1, n);
    while (m--)
    {
        long long l, r, x;
        scanf("%lld %lld %lld", &l, &r, &x);
        puts(query(1, l, r, x) ? "NO" : "YES");
    }
    return 0;
}