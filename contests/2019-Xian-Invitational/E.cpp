#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;
const int maxdigit = 33;

int arr[N], n;
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
    int dig[maxdigit]; // 区间各位上有多少个1
    int lazyset[maxdigit]; // 懒惰标记，向下赋值，为-1表示区间没有被完全覆盖
} tr[N << 2];

void pushup(int root, int pos)
{
    tr[root].dig[pos] = tr[lson].dig[pos] + tr[rson].dig[pos];
}

void pushdown(int root, int pos)
{
    if (tr[root].lazyset[pos] != -1) // 区间被完全覆盖
    {
        tr[lson].dig[pos] = (tr[lson].r - tr[lson].l + 1) * tr[root].lazyset[pos];
        tr[rson].dig[pos] = (tr[rson].r - tr[rson].l + 1) * tr[root].lazyset[pos];
        tr[lson].lazyset[pos] = tr[rson].lazyset[pos] = tr[root].lazyset[pos];
        tr[root].lazyset[pos] = -1;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    memset(tr[root].lazyset, -1, sizeof(tr[root].lazyset));
    if (l == r)
    {
        for (int i = 0; i < maxdigit; i++)
        {
            if (arr[rk[l]] & (1LL << i))
                tr[root].dig[i]++;
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    for (int i = 0; i < maxdigit; i++)
        pushup(root, i);
}

void update(int root, int l, int r, int pos, int val)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        tr[root].dig[pos] = (tr[root].r - tr[root].l + 1) * val;
        tr[root].lazyset[pos] = val;
        return;
    }
    pushdown(root, pos);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, r, pos, val);
    if (r > mid)
        update(rson, l, r, pos, val);
    pushup(root, pos);
}

int query(int root, int l, int r, int pos)
{
    if (l <= tr[root].l && r >= tr[root].r)
        return tr[root].dig[pos];
    pushdown(root, pos);
    int mid = (tr[root].l + tr[root].r) >> 1;
    int ans = 0;
    if (l <= mid)
        ans += query(lson, l, r, pos);
    if (r > mid)
        ans += query(rson, l, r, pos);
    return ans;
}

void updatePath(int x, int y, int pos, int val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        update(1, dfn[top[x]], dfn[x], pos, val);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    update(1, dfn[y], dfn[x], pos, val);
}

int queryPath(int x, int y, int pos)
{
    int ans = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        ans += query(1, dfn[top[x]], dfn[x], pos);
        x = fa[top[x]];
    }
    if (dep[x] < dep[y])
        swap(x, y);
    ans += query(1, dfn[y], dfn[x], pos);
    return ans;
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
    int n, m;
    scanf("%d %d", &n, &m);
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
    dfs1(1);
    dfs2(1, 1);
    build(1, 1, n);
    while (m--)
    {
        int op, s, t;
        scanf("%d %d %d", &op, &s, &t);
        if (op == 1)
        {
            for (int i = 0; i < maxdigit; i++)
            {
                if (t & (1LL << i))
                    updatePath(1, s, i, 1);
            }
        }
        else if (op == 2)
        {
            for (int i = 0; i < maxdigit; i++)
            {
                if ((t & (1LL << i)) == 0)
                    updatePath(1, s, i, 0);
            }
        }
        else if (op == 3)
        {
            long long ans = 0;
            for (int i = 0; i < maxdigit; i++)
                ans += (queryPath(1, s, i) & 1) * (1LL << i);
            if (ans ^ t)
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}