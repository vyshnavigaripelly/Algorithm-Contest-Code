#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;

int n;
long long arr[N], delta[N], bit[N];

struct SegTree
{
    int l, r;
    long long gcd, max;
} tr[N << 2];

void pushup(int root)
{
    tr[root].gcd = __gcd(tr[lson].gcd, tr[rson].gcd);
    tr[root].max = max(abs(tr[lson].max), abs(tr[rson].max));
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        tr[root].max = delta[l];
        tr[root].gcd = delta[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, long long val)
{
    if (tr[root].l == tr[root].r)
    {
        tr[root].max += val;
        tr[root].gcd += val;
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, val);
    else
        update(rson, l, val);
    pushup(root);
}

long long queryGcd(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].gcd;
    int mid = (tr[root].l + tr[root].r) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans = __gcd(ans, queryGcd(lson, l, r));
    if (r > mid)
        ans = __gcd(ans, queryGcd(rson, l, r));
    return abs(ans);
}

long long queryMax(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return abs(tr[root].max);
    int mid = (tr[root].l + tr[root].r) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans = max(ans, queryMax(lson, l, r));
    if (r > mid)
        ans = max(ans, queryMax(rson, l, r));
    return ans;
}

long long sum(int x)
{
    long long y = 0;
    for (; x; x -= x & -x)
        y += bit[x];
    return y;
}

void add(int x, long long y)
{
    for (; x <= n; x += x & -x)
        bit[x] += y;
}

int main()
{

    int m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        delta[i] = arr[i] - arr[i - 1];
    }
    build(1, 1, n);
    while (m--)
    {
        int op, l, r;
        long long val;
        scanf("%d %d %d", &op, &l, &r);
        if (op == 1)
        {
            scanf("%lld", &val);
            update(1, l, val);
            add(l, val);
            if (r < n)
            {
                update(1, r + 1, -val);
                add(r + 1, -val);
            }
        }
        else if (op == 2)
        {
            printf("%lld\n", l == r ? 0 : queryMax(1, l + 1, r));
        }
        else
        {
            long long ans1 = arr[l] + sum(l);
            long long ans2 = l < r ? queryGcd(1, l + 1, r) : 0;
            printf("%lld\n", __gcd(ans1, ans2));
        }
    }
    return 0;
}