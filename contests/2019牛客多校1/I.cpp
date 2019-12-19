#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
const long long INF = (1LL << 62) - 5;

long long disy[N];

struct Node
{
    long long x, y;
    long long a, b;
} arr[N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct
    {
        int l, r;
        long long maxn;
        long long lazyadd;
    } tr[N * 4];

    void pushup(int root)
    {
        tr[root].maxn = max(tr[lson].maxn, tr[rson].maxn);
    }

    void pushdown(int root)
    {
        if (tr[root].lazyadd != 0)
        {
            tr[lson].lazyadd += tr[root].lazyadd;
            tr[rson].lazyadd += tr[root].lazyadd;
            tr[lson].maxn += tr[root].lazyadd;
            tr[rson].maxn += tr[root].lazyadd;
            tr[root].lazyadd = 0;
        }
    }

    void build(int root, int l, int r)
    {
        tr[root].l = l, tr[root].r = r;
        if (l == r)
        {
            tr[root].maxn = -INF;
            tr[root].lazyadd = 0;
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(root);
    }

    void updateSet(int root, int pos, long long val)
    {
        if (tr[root].l == tr[root].r)
        {
            tr[root].maxn = val;
            return;
        }
        pushdown(root);
        int mid = (tr[root].l + tr[root].r) >> 1;
        if (pos <= mid)
            updateSet(lson, pos, val);
        else
            updateSet(rson, pos, val);
        pushup(root);
    }

    void updateAdd(int root, int l, int r, long long val)
    {
        if (tr[root].l >= l && tr[root].r <= r)
        {
            tr[root].maxn += val;
            tr[root].lazyadd += val;
            return;
        }
        pushdown(root);
        int mid = (tr[root].l + tr[root].r) >> 1;
        if (l <= mid)
            updateAdd(lson, l, r, val);
        if (r > mid)
            updateAdd(rson, l, r, val);
        pushup(root);
    }

    long long query(int root, int l, int r)
    {
        if (tr[root].l >= l && tr[root].r <= r)
        {
            return tr[root].maxn;
        }
        pushdown(root);
        int mid = (tr[root].l + tr[root].r) >> 1;
        long long ans = -INF;
        if (l <= mid)
            ans = max(ans, query(lson, l, r));
        if (r > mid)
            ans = max(ans, query(rson, l, r));
        return ans;
    }
} seg;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld %lld %lld %lld", &arr[i].x, &arr[i].y, &arr[i].a, &arr[i].b);
            disy[i] = arr[i].y;
        }
        disy[n + 1] = 0;
        sort(disy + 1, disy + 1 + n + 1);
        int tot = unique(disy + 1, disy + 1 + n + 1) - (disy + 1);
        for (int i = 1; i <= n; i++)
        {
            arr[i].y = lower_bound(disy + 1, disy + 1 + tot, arr[i].y) - (disy + 1) + 1;
        }
        sort(arr + 1, arr + 1 + n, [](const Node &a, const Node &b) {
            return a.x != b.x ? a.x < b.x : a.y > b.y;
        });
        seg.build(1, 1, tot + 1);
        seg.updateSet(1, 1, 0);
        for (int i = 1; i <= n; i++)
        {
            seg.updateSet(1, arr[i].y, seg.query(1, 1, arr[i].y) + arr[i].b);
            seg.updateAdd(1, 1, arr[i].y - 1, arr[i].a);
            seg.updateAdd(1, arr[i].y + 1, tot + 1, arr[i].b);
        }
        printf("%lld\n", seg.query(1, 1, tot + 1));
    }
    return 0;
}