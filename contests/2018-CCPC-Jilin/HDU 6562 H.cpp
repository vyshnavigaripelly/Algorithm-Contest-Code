#include <iostream>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;
const int mod = 1e9 + 7;

struct SegTree
{
    int l, r;
    long long sum; // 区间和
    long long addlenpow, addleft, addright; // 加数的幂系数、字符串前后加的数
    long long lenpow; // 10 ^ len(x)
} tr[N << 2];

void pushup(int root)
{
    tr[root].sum = (tr[lson].sum + tr[rson].sum) % mod;
    tr[root].lenpow = (tr[lson].lenpow + tr[rson].lenpow) % mod;
}

void pushdown(int root)
{
    if (tr[root].addlenpow > 1)
    {
        tr[lson].addleft = (tr[root].addleft * tr[lson].addlenpow % mod + tr[lson].addleft) % mod;
        tr[rson].addleft = (tr[root].addleft * tr[rson].addlenpow % mod + tr[rson].addleft) % mod;
        tr[lson].addright = (tr[lson].addright * tr[root].addlenpow % mod + tr[root].addright) % mod;
        tr[rson].addright = (tr[rson].addright * tr[root].addlenpow % mod + tr[root].addright) % mod;
        tr[lson].sum = (tr[root].addleft * tr[lson].lenpow % mod * tr[root].addlenpow % mod +
                        tr[lson].sum * tr[root].addlenpow % mod +
                        tr[root].addright * (tr[lson].r - tr[lson].l + 1) % mod) % mod;
        tr[rson].sum = (tr[root].addleft * tr[rson].lenpow % mod * tr[root].addlenpow % mod +
                        tr[rson].sum * tr[root].addlenpow % mod +
                        tr[root].addright * (tr[rson].r - tr[rson].l + 1) % mod) % mod;
        tr[lson].lenpow = tr[lson].lenpow * tr[root].addlenpow % mod * tr[root].addlenpow % mod;
        tr[rson].lenpow = tr[rson].lenpow * tr[root].addlenpow % mod * tr[root].addlenpow % mod;
        tr[lson].addlenpow = tr[lson].addlenpow * tr[root].addlenpow % mod;
        tr[rson].addlenpow = tr[rson].addlenpow * tr[root].addlenpow % mod;
        tr[root].addlenpow = 1;
        tr[root].addleft = tr[root].addright = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    tr[root].sum = tr[root].addleft = tr[root].addright = 0;
    tr[root].addlenpow = 1;
    if (l == r)
    {
        tr[root].lenpow = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int l, int r, int d)
{
    if (tr[root].l >= l && tr[root].r <= r)
    {
        tr[root].sum = (tr[root].lenpow * 10 * d % mod + tr[root].sum * 10 % mod + d * (tr[root].r - tr[root].l + 1)) % mod;
        tr[root].addleft = (tr[root].addlenpow * d + tr[root].addleft) % mod;
        tr[root].addright = (tr[root].addright * 10 + d) % mod;
        tr[root].lenpow = tr[root].lenpow * 100 % mod;
        tr[root].addlenpow = tr[root].addlenpow * 10 % mod;
        return;
    }
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid)
        update(lson, l, r, d);
    if (r > mid)
        update(rson, l, r, d);
    pushup(root);
}

long long query(int root, int l, int r)
{
    if (tr[root].l >= l && tr[root].r <= r)
        return tr[root].sum;
    pushdown(root);
    int mid = (tr[root].l + tr[root].r) >> 1;
    long long ans = 0;
    if (l <= mid)
        ans += query(lson, l, r);
    if (r > mid)
        ans += query(rson, l, r);
    return ans % mod;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        build(1, 1, n);
        printf("Case %d:\n", cas);
        while (m--)
        {
            int l, r;
            char op[10];
            scanf("%s %d %d", op, &l, &r);
            if (op[0] == 'w')
            {
                int d;
                scanf("%d", &d);
                update(1, l, r, d);
            }
            else
            {
                printf("%lld\n", query(1, l, r) % mod);
            }
        }
    }
    return 0;
}