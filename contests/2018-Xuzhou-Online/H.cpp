#include <iostream>

using namespace std;

const int N = 1e5 + 7;

long long arr[N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct Node
    {
        int l, r;
        long long sum, isum;
    } tr[N * 4];

    void pushup(int root)
    {
        tr[root].sum = tr[lson].sum + tr[rson].sum;
        tr[root].isum = tr[lson].isum + tr[rson].isum;
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 0, 0};
        if (l == r)
        {
            tr[root].sum = arr[l];
            tr[root].isum = l * arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(root);
    }

    void update(int root, int pos, long long val)
    {
        if (tr[root].l == tr[root].r)
        {
            tr[root].sum = val;
            tr[root].isum = tr[root].l * val;
            return;
        }
        int mid = (tr[root].l + tr[root].r) >> 1;
        if (pos <= mid)
            update(lson, pos, val);
        else
            update(rson, pos, val);
        pushup(root);
    }

    pair<long long, long long> query(int root, int l, int r)
    {
        if (l <= tr[root].l && r >= tr[root].r)
            return {tr[root].sum, tr[root].isum};
        int mid = (tr[root].l + tr[root].r) >> 1;
        pair<long long, long long> ans, p, q;
        if (l <= mid)
            p = query(lson, l, r);
        if (r > mid)
            q = query(rson, l, r);
        return {p.first + q.first, p.second + q.second};
    }
} seg;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    seg.build(1, 1, n);
    while (q--)
    {
        int op, b, c;
        scanf("%d %d %d", &op, &b, &c);
        if (op == 1)
        {
            auto tmp = seg.query(1, b, c);
            long long ans = tmp.first * 2 * (c - b + 1) - tmp.second - (c - b + 1 - b) * tmp.first;
            printf("%lld\n", ans);
        }
        else
        {
            seg.update(1, b, c);
        }
    }
    return 0;
}