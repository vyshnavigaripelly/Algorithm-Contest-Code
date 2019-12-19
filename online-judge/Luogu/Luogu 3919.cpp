#include <iostream>

using namespace std;

const int N = 1e6 + 7;

int arr[N];
int rt[N]; // root index

struct ChairmanTree
{
    int tot = 0; // total nodes

    struct Node
    {
        int l, r; // lson & rson node id
        int val;
    } tr[N * 24]; // (4 + logn) * n

    int build(int l, int r)
    {
        int root = ++tot;
        if (l == r)
        {
            tr[root].val = arr[l];
            return root;
        }
        int mid = (l + r) >> 1;
        tr[root].l = build(l, mid);
        tr[root].r = build(mid + 1, r);
        return root;
    }

    int update(int pre, int l, int r, int pos, int val)
    {
        int root = ++tot;
        tr[root] = tr[pre];
        if (l == r)
        {
            tr[root].val = val;
            return root;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            tr[root].l = update(tr[pre].l, l, mid, pos, val);
        else
            tr[root].r = update(tr[pre].r, mid + 1, r, pos, val);
        return root;
    }

    int query(int root, int l, int r, int pos)
    {
        if (l == r)
        {
            return tr[root].val;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid)
            return query(tr[root].l, l, mid, pos);
        else
            return query(tr[root].r, mid + 1, r, pos);
    }
} seg;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    rt[0] = seg.build(1, n);
    for (int i = 1; i <= m; i++)
    {
        int v, op, pos;
        scanf("%d %d %d", &v, &op, &pos);
        if (op == 1)
        {
            int val;
            scanf("%d", &val);
            rt[i] = seg.update(rt[v], 1, n, pos, val);
        }
        else
        {
            int ans = seg.query(rt[v], 1, n, pos);
            printf("%d\n", ans);
            rt[i] = rt[v];
        }
    }
    return 0;
}