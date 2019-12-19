#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 5e4 + 7;

int arr[N];

struct SegTree
{
    int l, r;
    int sum;
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

void update(int root, int pos, int val)
{
    if (tr[root].l == tr[root].r)
    {
        tr[root].sum += val;
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
        return tr[root].sum;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans += query(lson, l, r);
    if (r > mid)
        ans += query(rson, l, r);
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        build(1, 1, n);
        char op[10];
        printf("Case %d:\n", cas);
        while (scanf("%s", op) && strcmp(op, "End") != 0)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            if (op[0] == 'A')
            {
                update(1, a, b);
            }
            else if (op[0] == 'S')
            {
                update(1, a, -b);
            }
            else if (op[0] == 'Q')
            {
                printf("%d\n", query(1, a, b));
            }
        }
    }
    return 0;
}