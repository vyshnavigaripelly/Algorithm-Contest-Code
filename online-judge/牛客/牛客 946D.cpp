// https://ac.nowcoder.com/acm/contest/946/D
#include <iostream>
#include <cstdio>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;
const int mod = 1e9 + 7;

struct SegTree
{
    int l, r;
    long long sum, add;
};

struct SegTrees
{
    SegTree tr[N << 2];

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

    void update(int root, int l, int r, long long val)
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

    long long query(int root, int l, int r)
    {
        if (l <= tr[root].l && r >= tr[root].r)
            return tr[root].sum % mod;
        pushdown(root);
        int mid = (tr[root].l + tr[root].r) >> 1;
        long long ans = 0;
        if (l <= mid)
            (ans += query(lson, l, r)) %= mod;
        if (r > mid)
            (ans += query(rson, l, r)) %= mod;
        return ans;
    }
} numTree, opTree;

struct Operation
{
    int id, l, r;

    void input()
    {
        scanf("%d %d %d", &id, &l, &r);
    }
} op[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        op[i].input();
    }
    opTree.build(1, 1, m);
    numTree.build(1, 1, n);
    for (int i = m; i >= 1; i--)
    {
        if (op[i].id == 1)
        {
            numTree.update(1, op[i].l, op[i].r, opTree.query(1, i, i) + 1);
        }
        else
        {
            opTree.update(1, op[i].l, op[i].r, opTree.query(1, i, i) + 1);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%lld ", numTree.query(1, i, i) % mod);
    }
    puts("");
    return 0;
}