#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 3e5 + 7;

struct SegTree
{
    int l, r;
    int sum, add;
} tr[N << 2];

int arr[N];
int fa[N], dep[N], dfn[N], siz[N], son[N], rk[N], top[N];
int n, tot;
vector<int> edge[N];

void pushup(int root)
{
    tr[root].sum = tr[lson].sum + tr[rson].sum;
}

void pushdown(int root)
{
    if (tr[root].add)
    {
        tr[lson].sum += tr[root].add * (tr[lson].r - tr[lson].l + 1);
        tr[rson].sum += tr[root].add * (tr[rson].r - tr[rson].l + 1);
        tr[lson].add += tr[root].add;
        tr[rson].add += tr[root].add;
        tr[root].add = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        tr[root].sum = 0;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, int r, int val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].sum += val * (tr[root].r - tr[root].l + 1);
        tr[root].add += val;
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
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].sum;
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        return query(lson, l, r);
    if (r > mid)
        return query(rson, l, r);
}

void dfs1(int u)
{
    siz[u] = 1;
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (fa[v])
            continue;
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs1(v);
        siz[u] += siz[v];
        if (siz[son[u]] < siz[v])
        {
            son[u] = v;
        }
    }
}

void dfs2(int u, int t)
{
    top[u] = t;
    dfn[u] = ++tot;
    rk[tot] = u;
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (v != son[u] && v != fa[u])
        {
            dfs2(v, v);
        }
    }
}

void updatePath(int x, int y, int val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(1, dfn[top[x]], dfn[x], val);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    update(1, dfn[y], dfn[x], val);
}

int queryPath(int x, int y)
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
        {
            swap(x, y);
        }
        ans = query(1, dfn[top[x]], dfn[x]);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    ans = query(1, dfn[y], dfn[x]);
    return ans;
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    dep[1] = 1, fa[1] = 1;
    dfs1(1), dfs2(1, 1);
    build(1, 1, n);
    for (int i = 2; i <= n; i++)
    {
        updatePath(arr[i - 1], arr[i], 1);
        updatePath(arr[i], arr[i], -1);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", queryPath(i, i));
    }
    return 0;
}