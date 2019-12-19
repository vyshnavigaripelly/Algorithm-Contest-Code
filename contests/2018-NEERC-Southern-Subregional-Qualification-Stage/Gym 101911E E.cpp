#include <iostream>
#include <deque>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 3e5 + 7;

int n, m, vis[N];
int arr[N];
deque<int> que[N];

struct SegTree
{
    int l, r;
    int color, same;
} tr[N * 4];

void pushdown(int root)
{
    if (tr[root].same)
    {
        tr[lson].color = tr[rson].color = tr[root].color;
        tr[lson].same = tr[rson].same;
        tr[root].same = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    if (l == r)
    {
        tr[root].color = arr[l];
        tr[root].same = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}

void update(int root, int l, int r, int val)
{
    if (l <= tr[root].l && tr[root].r <= r)
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

int query(int root, int pos)
{
    if (tr[root].same)
    {
        return tr[root].color;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (pos <= mid)
        return query(lson, pos);
    if (pos > mid)
        return query(rson, pos);
    return -1;
}

int main()
{

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        que[arr[i]].push_back(i);
    }
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        int c;
        scanf("%d", &c);
        if (vis[c])
        {
            continue;
        }
        vis[c] = 1;
        while (que[c].size() && query(1, que[c].front()) != c)
        {
            que[c].pop_front();
        }
        while (que[c].size() && query(1, que[c].back()) != c)
        {
            que[c].pop_back();
        }
        if (que[c].size())
        {
            update(1, que[c].front(), que[c].back(), c);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", query(1, i));
    }
    return 0;
}