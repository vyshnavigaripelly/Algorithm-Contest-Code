#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 6e4 + 7;
const double INF = 1e50;
const double EPS = 1e-6;

int arr[N], pre[N], last[N];
int n;

struct SegTree
{
    int l, r;
    double dat, lazy;
} tr[N << 2];

void pushup(int root)
{
    tr[root].dat = min(tr[lson].dat, tr[rson].dat);
}

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

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].lazy = 0;
    if (l == r)
    {
        tr[root].dat = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, int r, double val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].dat += val;
        tr[root].lazy += val;
        return;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
    {
        update(lson, l, r, val);
    }
    if (r > mid)
    {
        update(rson, l, r, val);
    }
    pushup(root);
}

double query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        return tr[root].dat;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    double ans = INF;
    if (l <= mid)
    {
        ans = min(ans, query(lson, l, r));
    }
    if (r > mid)
    {
        ans = min(ans, query(rson, l, r));
    }
    pushup(root);
    return ans;
}

int check(double k)
{
    memset(tr, 0, sizeof(tr));
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        update(1, pre[i] + 1, i, 1.0);
        update(1, 1, i, -k);
        double tmp = query(1, 1, i);
        if (tmp <= 0)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(last, 0, sizeof(last));
        memset(pre, 0, sizeof(pre));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            pre[i] = last[arr[i]];
            last[arr[i]] = i;
        }
        double l = 0, r = 1;
        while (l + EPS < r)
        {
            double mid = (l + r) / 2;
            if (check(mid))
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        printf("%.6f\n", r);
    }
    return 0;
}