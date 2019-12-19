#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;

long long arr[N];

struct SegTree
{
    int l, r;
    long long sum;
} tr[N << 2];

void pushup(int root)
{
    tr[root].sum = tr[lson].sum + tr[rson].sum;
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    if (l == r)
    {
        tr[root].sum = arr[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, int r)
{
    if (tr[root].sum == tr[root].r - tr[root].l + 1)
    {
        return;
    }
    if (tr[root].l == tr[root].r)
    {
        tr[root].sum = sqrt(tr[root].sum);
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, r);
    if (r > mid)
        update(rson, l, r);
    pushup(root);
}

long long query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].sum;
    int mid = (tr[root].l + tr[root].r) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += query(lson, l, r);
    if (r > mid)
        ans += query(rson, l, r);
    return ans;
}

int main()
{
    int n;
    for (int cas = 1; ~scanf("%d", &n); cas++)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        build(1, 1, n);
        int m;
        scanf("%d", &m);
        printf("Case #%d:\n", cas);
        while (m--)
        {
            int op, l, r;
            scanf("%d %d %d", &op, &l, &r);
            if (l > r)
                swap(l, r);
            if (op == 0)
            {
                update(1, l, r);
            }
            else
            {
                printf("%lld\n", query(1, l, r));
            }
        }
        puts("");
    }
    return 0;
}