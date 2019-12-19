#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 7;

int arr[N], dis[N];
int rt[N]; // root index

struct ChairmanTree
{
    int tot = 0; // total nodes

    struct Node
    {
        int l, r; // lson & rson node id
        int cnt;
    } tr[N * 24]; // (4 + logn) * n

    void pushup(int root)
    {
        tr[root].cnt = tr[tr[root].l].cnt + tr[tr[root].r].cnt;
    }

    int build(int l, int r)
    {
        int root = ++tot;
        if (l == r)
        {
            return root;
        }
        int mid = (l + r) >> 1;
        tr[root].l = build(l, mid);
        tr[root].r = build(mid + 1, r);
        return root;
    }

    int update(int pre, int l, int r, int val)
    {
        int root = ++tot;
        tr[root] = tr[pre];
        if (l == r)
        {
            tr[root].cnt++;
            return root;
        }
        int mid = (l + r) >> 1;
        if (val <= mid)
            tr[root].l = update(tr[pre].l, l, mid, val);
        else
            tr[root].r = update(tr[pre].r, mid + 1, r, val);
        pushup(root);
        return root;
    }

    int query(int u, int v, int l, int r, int k)
    {
        if (l == r)
        {
            return l;
        }
        int lcnt = tr[tr[v].l].cnt - tr[tr[u].l].cnt;
        int mid = (l + r) >> 1;
        if (k <= lcnt)
            return query(tr[u].l, tr[v].l, l, mid, k);
        else
            return query(tr[u].r, tr[v].r, mid + 1, r, k - lcnt);
    }
} seg;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        dis[i] = arr[i];
    }
    sort(dis + 1, dis + 1 + n);
    int tot = unique(dis + 1, dis + 1 + n) - (dis + 1);
    rt[0] = seg.build(1, tot);
    for (int i = 1; i <= n; i++)
    {
        int t = lower_bound(dis + 1, dis + 1 + tot, arr[i]) - dis;
        rt[i] = seg.update(rt[i - 1], 1, tot, t);
    }
    while (q--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        int ans = seg.query(rt[l - 1], rt[r], 1, tot, k);
        printf("%d\n", dis[ans]);
    }
    return 0;
}