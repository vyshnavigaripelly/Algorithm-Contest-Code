#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;

long long arr[N];
int pre[N];

struct SegTree
{
    int l, r;
    long long sum, add;
} tr[N << 2];

void pushup(int root)
{
    tr[root].sum = tr[lson].sum + tr[rson].sum;
}

void pushdown(int root)
{
    if (tr[root].add)
    {
        tr[lson].sum += tr[root].add * (tr[lson].r - tr[lson].l + 1);
        tr[rson].sum += tr[root].add * (tr[rson].r - tr[rson].l + 1);
        tr[lson].add += tr[root].add;
        tr[rson].add += tr[root].add;
        tr[root].add = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        tr[root].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, int r, long long val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].sum += val * (tr[root].r - tr[root].l + 1);
        tr[root].add += val;
        return;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, r, val);
    if (r > mid)
        update(rson, l, r, val);
    pushup(root);
}

long long query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].sum;
    pushdown(root);
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
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    build(1, 1, n);
    long long ans = 0;
    memset(pre, 0, sizeof(pre));
    for (int i = 1; i <= n; i++)
    {
        update(1, pre[arr[i]] + 1, i, 1);
        ans += query(1, 1, n);
        pre[arr[i]] = i;
    }
    printf("%lld\n", ans);
    return 0;
}