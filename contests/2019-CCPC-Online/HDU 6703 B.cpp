#include <iostream>
#include <algorithm>
#include <cstring>
#include <set>

using namespace std;

const int N = 1e5 + 7;
const int INF = (1 << 30) - 5;

int arr[N], rt[N];
set<int> se;

struct ChairmanTree
{
    int tot = 0;

    struct Node
    {
        int l, r;
        int cnt;
    } tr[N * 24];

    void init()
    {
        tot = 0;
        memset(tr, 0, sizeof(tr));
    }

    void pushup(int root)
    {
        tr[root].cnt = tr[tr[root].l].cnt + tr[tr[root].r].cnt;
    }

    int build(int l, int r)
    {
        int root = ++tot;
        if (l == r)
            return root;
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
            tr[root].l = update(tr[root].l, l, mid, val);
        else
            tr[root].r = update(tr[root].r, mid + 1, r, val);
        pushup(root);
        return root;
    }

    int query(int u, int v, int l, int r, int k)
    {
        if (l == r)
        {
            return l;
        }
        int mid = (l + r) >> 1;
        int lcnt = tr[tr[v].l].cnt - tr[tr[u].l].cnt,
            rcnt = tr[tr[v].r].cnt - tr[tr[u].r].cnt;
        int ans = INF;
        if (lcnt != 0 && k <= mid)
            ans = query(tr[u].l, tr[v].l, l, mid, k);
        if (ans != INF)
            return ans;
        if (rcnt != 0)
            ans = query(tr[u].r, tr[v].r, mid + 1, r, k);
        return ans;
    }
} seg;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        seg.init();
        se.clear();
        memset(rt, 0, sizeof(rt));
        int n, m, lastans = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        rt[0] = seg.build(1, n);
        for (int i = 1; i <= n; i++)
        {
            rt[i] = seg.update(rt[i - 1], 1, n, arr[i]);
        }
        while (m--)
        {
            int op;
            scanf("%d", &op);
            if (op == 1)
            {
                int pos;
                scanf("%d", &pos);
                pos ^= lastans;
                se.insert(arr[pos]);
            }
            else
            {
                int r, k;
                scanf("%d %d", &r, &k);
                r ^= lastans;
                k ^= lastans;
                int ans = seg.query(rt[r], rt[n], 1, n, k);
                auto it = se.lower_bound(k);
                if (it != se.end())
                {
                    ans = min(ans, *it);
                }
                ans = min(ans, n + 1);
                lastans = ans;
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}