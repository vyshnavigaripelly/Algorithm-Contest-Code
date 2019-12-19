#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 2e3 + 7;
const long long INF = 1LL << 62;

vector<pair<int, long long>> row[N];
int disx[N], disy[N];

struct Node
{
    long long x, y, w;
} arr[N];

struct SegTree
{
    int l, r;
    long long sum, lmax, rmax, dat;
} tr[N * 4];

void pushup(int root)
{
    tr[root].sum = tr[lson].sum + tr[rson].sum;
    tr[root].lmax = max(tr[lson].lmax, tr[lson].sum + tr[rson].lmax);
    tr[root].rmax = max(tr[rson].rmax, tr[lson].rmax + tr[rson].sum);
    tr[root].dat = max({tr[lson].dat, tr[rson].dat, tr[lson].rmax + tr[rson].lmax});
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        tr[root].dat = tr[root].sum = tr[root].lmax = tr[root].rmax = 0;
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
        tr[root].dat = tr[root].sum = tr[root].lmax = tr[root].rmax = tr[root].sum + val;
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
    ans.dat = max({ll.dat, rr.dat, ll.rmax + rr.lmax});
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i <= n; i++)
        {
            row[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld %lld", &arr[i].x, &arr[i].y, &arr[i].w);
            disx[i] = arr[i].x;
            disy[i] = arr[i].y;
        }
        sort(disx + 1, disx + 1 + n);
        sort(disy + 1, disy + 1 + n);
        int totx = unique(disx + 1, disx + 1 + n) - (disx + 1);
        int toty = unique(disy + 1, disy + 1 + n) - (disy + 1);
        for (int i = 1; i <= n; i++)
        {
            int tx = lower_bound(disx + 1, disx + 1 + totx, arr[i].x) - disx;
            int ty = lower_bound(disy + 1, disy + 1 + toty, arr[i].y) - disy;
            row[tx].push_back({ty, arr[i].w});
        }
        long long ans = 0;
        for (int i = 1; i <= totx; i++) // upper
        {
            build(1, 1, toty);
            for (int j = i; j <= totx; j++) // lower
            {
                for (auto k : row[j])
                {
                    update(1, k.first, k.second);
                }
                ans = max(ans, query(1, 1, toty).dat);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}