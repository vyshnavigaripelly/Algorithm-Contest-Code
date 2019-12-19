#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

int arr[N], cur[N];
vector<int> pos[N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct Node
    {
        int l, r;
        int maxn;
        int lazyadd;
    } tr[N * 4];

    void pushup(int root)
    {
        tr[root].maxn = max(tr[lson].maxn, tr[rson].maxn);
    }

    void pushdown(int root)
    {
        if (tr[root].lazyadd != 0)
        {
            tr[lson].lazyadd += tr[root].lazyadd;
            tr[rson].lazyadd += tr[root].lazyadd;
            tr[lson].maxn += tr[root].lazyadd;
            tr[rson].maxn += tr[root].lazyadd;
            tr[root].lazyadd = 0;
        }
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 0, 0};
        if (l == r)
        {
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }

    void update(int root, int l, int r, int val)
    {
        if (tr[root].l >= l && tr[root].r <= r)
        {
            tr[root].maxn += val;
            tr[root].lazyadd += val;
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

    int query(int root, int l, int r, int c)
    {
        if (tr[root].l == tr[root].r)
        {
            return tr[root].l;
        }
        pushdown(root);
        if (tr[lson].maxn == c)
            return query(lson, l, r, c);
        else if (tr[rson].maxn == c)
            return query(rson, l, r, c);
        else
            return -1;
    }
} seg;

int main()
{
    int n, c, k;
    while (~scanf("%d %d %d", &n, &c, &k))
    {
        for (int i = 1; i <= c; i++)
        {
            pos[i].clear();
            pos[i].push_back(0);
        }
        memset(cur, 0, sizeof(cur));
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            pos[arr[i]].push_back(i);
        }
        if (k == 1)
        {
            printf("%d\n", n);
            continue;
        }
        seg.build(1, 1, n);
        memset(cur, 0, sizeof(cur));
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            cur[arr[i]]++;
            seg.update(1, i, i, c - 1);
            if (pos[arr[i]][cur[arr[i]] - 1] < pos[arr[i]][cur[arr[i]]] - 1)
                seg.update(1, pos[arr[i]][cur[arr[i]] - 1] + 1, pos[arr[i]][cur[arr[i]]] - 1, -1);
            if (cur[arr[i]] >= k)
                seg.update(1, pos[arr[i]][cur[arr[i]] - k] + 1, pos[arr[i]][cur[arr[i]] - k + 1], 1);
            int tmp = seg.query(1, 1, n, c);
            if (tmp != -1)
                ans = max(ans, i - tmp + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}