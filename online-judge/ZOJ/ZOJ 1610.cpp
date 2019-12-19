#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 8007;

int ans[N], last = -1;

struct SegTree
{
    int l, r;
    int color;
} tr[N << 2];

void pushdown(int root)
{
    if (tr[root].color != -1)
    {
        tr[lson].color = tr[rson].color = tr[root].color;
        tr[root].color = -1;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].color = -1;
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
        return;
    }
    if (tr[root].color == val)
    {
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
    if (tr[root].l == tr[root].r)
    {
        if (tr[root].color != -1 && tr[root].color != last)
        {
            ans[tr[root].color]++;
        }
        last = tr[root].color;
        return;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        query(lson, l, r);
    if (r > mid)
        query(rson, l, r);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(ans, 0, sizeof(ans));
        build(1, 1, 8000);
        for (int i = 0; i < n; i++)
        {
            int l, r, c;
            scanf("%d %d %d", &l, &r, &c);
            if (l < r)
            {
                update(1, l + 1, r, c);
            }
        }
        query(1, 1, 8000);
        for (int i = 0; i <= 8000; i++)
        {
            if (ans[i] == 0)
            {
                continue;
            }
            printf("%d %d\n", i, ans[i]);
        }
        puts("");
    }
    return 0;
}