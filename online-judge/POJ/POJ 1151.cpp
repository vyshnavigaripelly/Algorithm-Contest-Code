#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 107;

struct SegTree
{
    int l, r;
    int cover;
    double len;
} tr[(2 * N) << 2];

struct Line
{
    double x, y1, y2;
    int val;
} arr[N * 2];

double yraw[N * 2];
map<double, int> yval;

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].cover = tr[root].len = 0;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int root, int l, int r, int val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].cover += val;
        if (tr[root].cover > 0)
        {
            tr[root].len = yraw[tr[root].r + 1] - yraw[tr[root].l];
        }
        else
        {
            tr[root].len = 0;
        }
    }
    if (tr[root].l == tr[root].r)
    {
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
    {
        update(lson, l, r, val);
    }
    if (r > mid)
    {
        update(rson, l, r, val);
    }
    if (tr[root].cover > 0)
    {
        tr[root].len = yraw[tr[root].r + 1] - yraw[tr[root].l];
    }
    else
    {
        tr[root].len = tr[lson].len + tr[rson].len;
    }
}

int cmp(const Line &a, const Line &b)
{
    return a.x < b.x;
}

int main()
{
    int n;
    for (int cas = 1; ~scanf("%d", &n) && n; cas++)
    {
        yval.clear();
        for (int i = 1; i <= n; i++)
        {
            double x1, y1, x2, y2;
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            arr[i] = (Line){x1, y1, y2, 1};
            arr[i + n] = (Line){x2, y1, y2, -1};
            yraw[i] = y1;
            yraw[i + n] = y2;
        }
        n *= 2;
        sort(arr + 1, arr + 1 + n, cmp);
        sort(yraw + 1, yraw + 1 + n);
        int tot = unique(yraw + 1, yraw + 1 + n) - (yraw + 1);
        for (int i = 1; i <= tot; i++)
        {
            yval[yraw[i]] = i;
        }
        build(1, 1, tot - 1);
        double ans = 0;
        for (int i = 1; i < n; i++)
        {
            update(1, yval[arr[i].y1], yval[arr[i].y2] - 1, arr[i].val);
            ans += tr[1].len * (arr[i + 1].x - arr[i].x);
        }
        printf("Test case #%d\nTotal explored area: %.2f\n\n", cas, ans);
    }
    return 0;
}