#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;
const int V = 1e6 + 7;

int arr[N], rt[N];

struct ChairmanTree
{
    int tot;

    struct Node
    {
        int l, r;
        int cnt;
    } tr[V * 24];

    void init()
    {
        memset(tr, 0, (tot + 5) * sizeof(*tr));
        tot = 0;
    }

    void pushup(int root)
    {
        tr[root].cnt = tr[tr[root].l].cnt + tr[tr[root].r].cnt;
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

    int query(int u, int v, int l, int r, int ql, int qr)
    {
        if (l >= ql && r <= qr)
        {
            return tr[v].cnt - tr[u].cnt;
        }
        int mid = (l + r) >> 1;
        int ans = 0;
        if (ql <= mid)
            ans += query(tr[u].l, tr[v].l, l, mid, ql, qr);
        if (qr > mid)
            ans += query(tr[u].r, tr[v].r, mid + 1, r, ql, qr);
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
        memset(rt, 0, sizeof(rt));
        int n, q;
        scanf("%d %d", &n, &q);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            rt[i] = seg.update(rt[i - 1], 1, V, arr[i]);
        }
        int lastans = 0;
        while (q--)
        {
            int l, r, p, k;
            scanf("%d %d %d %d", &l, &r, &p, &k);
            l ^= lastans, r ^= lastans, p ^= lastans, k ^= lastans;
            int ansl = 0, ansr = V;
            while (ansl <= ansr)
            {
                int ansm = (ansl + ansr) >> 1;
                int ql = max(1, p - ansm), qr = min(V, p + ansm);
                if (seg.query(rt[l - 1], rt[r], 1, V, ql, qr) < k)
                    ansl = ansm + 1;
                else
                    ansr = ansm - 1;
            }
            lastans = ansl;
            printf("%d\n", ansl);
        }
    }
    return 0;
}