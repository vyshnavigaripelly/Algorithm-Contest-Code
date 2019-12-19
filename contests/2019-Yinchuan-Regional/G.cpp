#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;
const int d[4] = {2, 3, 5, 7};

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct SegNode
    {
        int l, r;
        int maxn[4];
        int lazyadd[4];
    } tr[N * 4];

    void pushup(int root)
    {
        for (int i = 0; i < 4; i++)
        {
            tr[root].maxn[i] = max(tr[lson].maxn[i], tr[rson].maxn[i]);
        }
    }

    void pushdown(int root)
    {
        for (int i = 0; i < 4; i++)
        {
            if (tr[root].lazyadd[i] != 0)
            {
                tr[lson].lazyadd[i] += tr[root].lazyadd[i];
                tr[rson].lazyadd[i] += tr[root].lazyadd[i];
                tr[lson].maxn[i] += tr[root].lazyadd[i];
                tr[rson].maxn[i] += tr[root].lazyadd[i];
                tr[root].lazyadd[i] = 0;
            }
        }
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 0, 0};
        if (l == r)
            return;
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }

    void update(int root, int l, int r, int val[])
    {
        if (tr[root].l >= l && tr[root].r <= r)
        {
            for (int i = 0; i < 4; i++)
            {
                tr[root].maxn[i] += val[i];
                tr[root].lazyadd[i] += val[i];
            }
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

    int query(int root, int l, int r)
    {
        if (tr[root].l >= l && tr[root].r <= r)
        {
            return *max_element(tr[root].maxn, tr[root].maxn + 4);
        }
        pushdown(root);
        int mid = (tr[root].l + tr[root].r) >> 1;
        int ans = 0;
        if (l <= mid)
            ans = max(ans, query(lson, l, r));
        if (r > mid)
            ans = max(ans, query(rson, l, r));
        return ans;
    }

#undef lson
#undef rson
} seg;

int main()
{

    int n, q;
    scanf("%d %d", &n, &q);
    seg.build(1, 1, n);
    while (q--)
    {
        char op[20];
        int l, r, x;
        scanf("%s %d %d", op, &l, &r);
        if (op[1] == 'U')
        {
            scanf("%d", &x);
            int cnt[4] = {0};
            for (int i = 0; i < 4; i++)
            {
                while (x % d[i] == 0)
                {
                    cnt[i]++;
                    x /= d[i];
                }
            }
            seg.update(1, l, r, cnt);
        }
        else
        {
            printf("ANSWER %d\n", seg.query(1, l, r));
        }
    }
    return 0;
}