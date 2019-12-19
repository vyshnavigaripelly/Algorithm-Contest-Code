#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 10007;

struct SegTree
{
    int l, r;
    long long dat, lazy;
} tr[(2 * N) << 2];

struct Line
{
    long long x, y1, y2, val;
} arr[N * 2];

long long yraw[N * 2];
map<long long, long long> yval;

void pushdown(int root)
{
    if (tr[root].lazy)
    {
        tr[lson].dat += tr[root].lazy;
        tr[rson].dat += tr[root].lazy;
        tr[lson].lazy += tr[root].lazy;
        tr[rson].lazy += tr[root].lazy;
        tr[root].lazy = 0;
    }
}

void build(int root, long long l, long long r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].dat = tr[root].lazy = 0;
    if (l == r)
    {
        return;
    }
    long long mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int root, long long l, long long r, long long val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].dat += val;
        tr[root].lazy += val;
        return;
    }
    pushdown(root);
    long long mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
    {
        update(lson, l, r, val);
    }
    if (r > mid)
    {
        update(rson, l, r, val);
    }
    tr[root].dat = max(tr[lson].dat, tr[rson].dat);
}

int cmp(const Line &a, const Line &b)
{
    return a.x < b.x || (a.x == b.x && a.val < b.val);
}

int main()
{
    int n;
    long long w, h;
    while (~scanf("%d %lld %lld", &n, &w, &h))
    {
        yval.clear();
        for (int i = 1; i <= n; i++)
        {
            long long x, y, c;
            scanf("%lld %lld %lld", &x, &y, &c);
            arr[i] = (Line){x, y, y + h, c};
            arr[i + n] = (Line){x + w, y, y + h, -c};
            yraw[i] = y;
            yraw[i + n] = y + h;
        }
        n *= 2;
        sort(arr + 1, arr + 1 + n, cmp);
        sort(yraw + 1, yraw + 1 + n);
        int tot = unique(yraw + 1, yraw + 1 + n) - (yraw + 1);
        for (int i = 1; i <= tot; i++)
        {
            yval[yraw[i]] = i;
        }
        build(1, 1, tot);
        long long ans = 0;
        for (int i = 1; i <= n; i++)
        {
            update(1, yval[arr[i].y1], yval[arr[i].y2] - 1, arr[i].val);
            ans = max(ans, tr[1].dat);
        }
        printf("%lld\n", ans);
    }
    return 0;
}