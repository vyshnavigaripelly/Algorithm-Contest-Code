#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 50007;

int pos[N], cnt[N], tot, fa[N];
vector<int> edge[N];

struct SegTree
{
    int l, r;
    int dat;
} tr[N << 2];

void dfs(int u, int pre)
{
    cnt[u] = 1;
    pos[u] = ++tot;
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (v == pre)
            continue;
        dfs(v, u);
        cnt[u] += cnt[v];
    }
}

void pushdown(int root)
{
    if (tr[root].dat != -1)
    {
        tr[lson].dat = tr[rson].dat = tr[root].dat;
        tr[root].dat = -1;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].dat = -1;
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
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].dat = val;
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
    if (tr[root].l == tr[root].r)
    {
        return tr[root].dat;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (pos <= mid)
        return query(lson, pos);
    else
        return query(rson, pos);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        tot = 0;
        int n, m, root = -1;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            edge[i].clear();
            pos[i] = cnt[i] = 0;
        }
        memset(fa, -1, sizeof(fa));
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edge[v].push_back(u);
            fa[u] = v;
        }
        for (int i = 1; i <= n; i++)
        {
            if (fa[i] == -1)
            {
                root = i;
                break;
            }
        }
        dfs(root, -1);
        build(1, 1, n);
        printf("Case #%d:\n", cas);
        scanf("%d", &m);
        while (m--)
        {
            char op[5];
            int x, y;
            scanf("%s", op);
            if (op[0] == 'T')
            {
                scanf("%d %d", &x, &y);
                update(1, pos[x], pos[x] + cnt[x] - 1, y);
            }
            else if (op[0] == 'C')
            {
                scanf("%d", &x);
                printf("%d\n", query(1, pos[x]));
            }
        }
    }
    return 0;
}