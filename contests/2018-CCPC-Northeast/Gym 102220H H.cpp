#include <iostream>

using namespace std;

const int N = 1e5 + 7;

long long arr[N], dif[N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct Node
    {
        int l, r;
        long long val, sum;
    } tr[N * 4];

    void pushup(int root)
    {
        tr[root].sum = tr[lson].sum + tr[rson].sum;
        tr[root].val = tr[lson].val + tr[rson].val;
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 0, 0};
        if (l == r)
        {
            tr[root].val = dif[l];
            tr[root].sum = max(0LL, dif[l]);
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
            tr[root].val += val;
            tr[root].sum = max(0LL, tr[root].val);
            return;
        }
        int mid = (tr[root].l + tr[root].r) >> 1;
        if (pos <= mid)
            update(lson, pos, val);
        else
            update(rson, pos, val);
        pushup(root);
    }

    long long query(int root, int l, int r, int flag)
    {
        if (l > r)
            return 0;
        if (l <= tr[root].l && r >= tr[root].r)
            return flag == 1 ? tr[root].sum : tr[root].val;
        int mid = (tr[root].l + tr[root].r) >> 1;
        long long ans = 0;
        if (l <= mid)
            ans += query(lson, l, r, flag);
        if (r > mid)
            ans += query(rson, l, r, flag);
        return ans;
    }

#undef lson
#undef rson
} seg;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            dif[i] = arr[i] - arr[i - 1];
        }
        dif[n + 1] = dif[n + 2] = 0;
        seg.build(1, 1, n);
        while (m--)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                int l, r, k;
                scanf("%d %d %d", &l, &r, &k);
                seg.update(1, l, k);
                if (r + 1 <= n)
                    seg.update(1, r + 1, -k);
            }
            else
            {
                int l, r;
                scanf("%d %d", &l, &r);
                long long ans;
                if (l == r)
                    ans = seg.query(1, 1, l, 0);
                else
                    ans = seg.query(1, l + 1, r, 1) + seg.query(1, 1, l, 0);
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}