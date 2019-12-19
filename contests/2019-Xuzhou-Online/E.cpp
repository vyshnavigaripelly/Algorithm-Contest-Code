#include <iostream>

using namespace std;

const int N = 5e5 + 7;
const long long INF = (1LL << 62) - 5;

long long arr[N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct Node
    {
        int l, r;
        long long maxn;
    } tr[N * 4];

    void pushup(int root)
    {
        tr[root].maxn = max(tr[lson].maxn, tr[rson].maxn);
    }

    void build(int root, int l, int r)
    {
        tr[root].l = l, tr[root].r = r;
        if (l == r)
        {
            tr[root].maxn = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(root);
    }

    long long query(int root, int l, int r, long long val)
    {
        if (tr[root].r < l)
            return -1;
        if (tr[root].l == tr[root].r)
            return tr[root].l;
        long long ans = -1;
        if (tr[rson].maxn >= val)
            ans = query(rson, l, r, val);
        if (ans != -1)
            return ans;
        return query(lson, l, r, val);
    }
} seg;

int main()
{
    long long n, m;
    scanf("%lld %lld", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    seg.build(1, 1, n);
    for (int i = 1; i <= n - 1; i++)
    {
        long long ans = seg.query(1, i + 1, n, arr[i] + m);
        if (ans == -1)
            printf("%lld ", -1LL);
        else
            printf("%lld ", ans - i - 1);
    }
    printf("-1");
    return 0;
}