#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 200000 + 10;

int mod, arr[N], n;
int fa[N], // 保存结点u的父亲节点
    dep[N], // 保存结点u的深度值
    dfn[N], // 保存树中每个节点剖分以后的新编号（DFS的执行顺序）
    siz[N], // 保存以u为根的子树节点个数
    son[N], // 保存重儿子
    rk[N], // 保存当前dfs标号在树中所对应的节点
    top[N], // 保存当前节点所在链的顶端节点
    tot;
vector<int> edge[N];

struct SegTree
{
    int l, r;
    int sum, add;
} tr[N << 2];

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
        tr[lson].sum %= mod;
        tr[rson].sum %= mod;
        tr[root].add = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l, tr[root].r = r;
    if (l == r)
    {
        tr[root].sum = arr[rk[l]] % mod;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

int query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].sum % mod;
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans += query(lson, l, r) % mod;
    if (r > mid)
        ans += query(rson, l, r) % mod;
    return ans % mod;
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

// 从x到y结点最短路径上所有节点的值都加上val
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

// 从x到y结点最短路径上所有节点的值之和
int queryPath(int x, int y)
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans += query(1, dfn[top[x]], dfn[x]);
        ans %= mod;
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    ans += query(1, dfn[y], dfn[x]);
    return ans % mod;
}

// 以x为根节点的子树内所有节点值都加上val
void updateChildren(int x, int val)
{
    update(1, dfn[x], dfn[x] + siz[x] - 1, val); // 子树区间右端点为dfn[x]+siz[x]-1
}

// 求以x为根节点的子树内所有节点值之和
int queryChildren(int x)
{
    return query(1, dfn[x], dfn[x] + siz[x] - 1);
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
            son[u] = v;
    }
}

void dfs2(int u, int t) // 当前节点、重链顶端
{
    top[u] = t;
    dfn[u] = ++tot; // 标记dfs序
    rk[tot] = u; // 序号tot对应节点u
    if (!son[u])
        return;
    dfs2(son[u], t);
    for (int i = 0; i < edge[u].size(); i++)
    {
        int v = edge[u][i];
        if (v != son[u] && v != fa[u])
            dfs2(v, v);
    }
}

int main()
{
    int n, m, r;
    scanf("%d %d %d %d", &n, &m, &r, &mod);
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
    dep[r] = 1, fa[r] = 1;
    dfs1(r);
    dfs2(r, r);
    build(1, 1, n);
    while (m--)
    {
        int op, x, y, z;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d %d", &x, &y, &z);
            updatePath(x, y, z);
        }
        else if (op == 2)
        {
            scanf("%d %d", &x, &y);
            printf("%d\n", queryPath(x, y));
        }
        else if (op == 3)
        {
            scanf("%d %d", &x, &z);
            updateChildren(x, z);
        }
        else
        {
            scanf("%d", &x);
            printf("%d\n", queryChildren(x));
        }
    }
    return 0;
}