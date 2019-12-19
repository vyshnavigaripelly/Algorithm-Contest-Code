#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 200000 + 7;

int arr[N];

struct SegTree
{
    int l, r;
    int max;
} tr[N << 2];

void pushup(int root)
{
    tr[root].max = max(tr[lson].max, tr[rson].max);
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    if (l == r)
    {
        tr[root].max = arr[l];
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
        tr[root].max = val;
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (pos <= mid)
        update(lson, pos, val);
    else
        update(rson, pos, val);
    pushup(root);
}

int query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        return tr[root].max;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans = max(ans, query(lson, l, r));
    if (r > mid)
        ans = max(ans, query(rson, l, r));
    return ans;
}

int main()
{

    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        build(1, 1, n);
        while (m--)
        {
            char op;
            int a, b;
            scanf(" %c %d %d", &op, &a, &b);
            if (op == 'U')
            {
                update(1, a, b);
            }
            else if (op == 'Q')
            {
                printf("%d\n", query(1, a, b));
            }
        }
    }
    return 0;
}