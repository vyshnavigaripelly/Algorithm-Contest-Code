#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 100000 + 7;

int vis[35];
int ans;

struct SegTree
{
    int l, r;
    int color, same;
} tr[N << 2];

void pushdown(int root)
{
    if (tr[root].same)
    {
        tr[lson].color = tr[rson].color = tr[root].color;
        tr[lson].same = tr[rson].same = 1;
        tr[root].same = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].color = tr[root].same = 1;
    if (l == r)
        return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int root, int l, int r, int val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].color = val;
        tr[root].same = 1;
        return;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, r, val);
    if (r > mid)
        update(rson, l, r, val);
}

void query(int root, int l, int r)
{
    if (tr[root].same)
    {
        if (!vis[tr[root].color])
        {
            vis[tr[root].color] = 1;
            ans++;
        }
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        query(lson, l, r);
    if (r > mid)
        query(rson, l, r);
}

int main()
{
    int n, t, q;
    scanf("%d %d %d", &n, &t, &q);
    build(1, 1, n);
    while (q--)
    {
        char op;
        int l, r, val;
        scanf(" %c %d %d", &op, &l, &r);
        if (l > r)
        {
            swap(l, r);
        }
        if (op == 'C')
        {
            scanf("%d", &val);
            update(1, l, r, val);
        }
        else
        {
            memset(vis, 0, sizeof(vis));
            ans = 0;
            query(1, l, r);
            printf("%d\n", ans);
        }
    }
    return 0;
}