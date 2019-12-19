#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 50007;
const int INF = 1 << 30;

int arr[N];

struct SegTree
{
    int l, r;
    int sum, lmax, rmax, dat;
} tr[N * 4];

void pushup(int root)
{
    tr[root].sum = tr[lson].sum + tr[rson].sum;
    tr[root].lmax = max(tr[lson].lmax, tr[lson].sum + tr[rson].lmax);
    tr[root].rmax = max(tr[rson].rmax, tr[lson].rmax + tr[rson].sum);
    tr[root].dat = max(max(tr[lson].dat, tr[rson].dat), tr[lson].rmax + tr[rson].lmax);
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    if (l == r)
    {
        tr[root].dat = tr[root].sum = tr[root].lmax = tr[root].rmax = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int pos, int val)
{
    if (tr[root].l == tr[root].r)
    {
        tr[root].sum = tr[root].lmax = tr[root].rmax = tr[root].dat = val;
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (pos <= mid)
    {
        update(lson, pos, val);
    }
    else
    {
        update(rson, pos, val);
    }
    pushup(root);
}

SegTree query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        return tr[root];
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    SegTree ll = {0, 0, -INF, -INF, -INF, -INF},
            rr = {0, 0, -INF, -INF, -INF, -INF},
            ans = {0, 0, 0, 0, 0, 0};
    if (l <= mid)
    {
        ll = query(lson, l, r);
        ans.sum += ll.sum;
    }
    if (r > mid)
    {
        rr = query(rson, l, r);
        ans.sum += rr.sum;
    }
    ans.lmax = max(ll.lmax, ll.sum + rr.lmax);
    ans.rmax = max(rr.rmax, rr.sum + ll.rmax);
    ans.dat = max(max(ll.dat, rr.dat), ll.rmax + rr.lmax);
    if (l > mid)
    {
        ans.lmax = max(ans.lmax, rr.lmax);
    }
    if (r <= mid)
    {
        ans.rmax = max(ans.rmax, ll.rmax);
    }
    return ans;
}

int main()
{
    int n, m;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int op, x, y;
        scanf("%d %d %d", &op, &x, &y);
        if (op == 0)
        {
            update(1, x, y);
        }
        else
        {
            printf("%d\n", query(1, x, y).dat);
        }
    }
    return 0;
}