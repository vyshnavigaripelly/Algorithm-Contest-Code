#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e5 + 7;
const int mod = 1e9 + 7;

char str[N];
long long mul[20] = {1};

inline int sod(int n)
{
    return (n - 1) % 15 + 1;
}

int getnum(char c)
{
    if (isdigit(c))
    {
        return c - '0';
    }
    else
    {
        return c - 'A' + 10;
    }
}

struct SegTree
{
    int l, r;
    long long dat[16];
} tr[N * 4];

void merge(SegTree &root, SegTree &a, SegTree &b)
{
    memset(root.dat, 0, sizeof(root.dat));
    for (int i = 0; i < 16; i++)
    {
        root.dat[i] = (root.dat[i] + a.dat[i] + b.dat[i]) % mod;
    }
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
        {
            int sum = sod(i + j);
            root.dat[sum] = (root.dat[sum] + a.dat[i] * b.dat[j] % mod) % mod;
        }
    }
}

void pushup(int root)
{
    merge(tr[root], tr[lson], tr[rson]);
}

void build(int root, int l, int r)
{
    memset(tr[root].dat, 0, sizeof(tr[root].dat));
    tr[root].l = l;
    tr[root].r = r;
    if (l == r)
    {
        tr[root].dat[getnum(str[l])] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void update(int root, int pos, int val)
{
    if (tr[root].l == tr[root].r)
    {
        memset(tr[root].dat, 0, sizeof(tr[root].dat));
        tr[root].dat[val] = 1;
        return;
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (pos <= mid)
    {
        update(lson, pos, val);
    }
    else
    {
        update(rson, pos, val);
    }
    pushup(root);
}

SegTree query(int root, int l, int r)
{
    if (l <= tr[root].l && r >= tr[root].r)
    {
        return tr[root];
    }
    int mid = (tr[root].l + tr[root].r) >> 1;
    if (l <= mid && r > mid)
    {
        SegTree ans = {0}, ll = query(lson, l, r), rr = query(rson, l, r);
        merge(ans, ll, rr);
        return ans;
    }
    if (l <= mid)
    {
        return query(lson, l, r);
    }
    else
    {
        return query(rson, l, r);
    }
}

int main()
{
    for (int i = 1; i < 16; i++)
    {
        mul[i] = mul[i - 1] * 1021 % mod;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    scanf("%s", str + 1);
    build(1, 1, n);
    while (m--)
    {
        int op, x, y;
        char c;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %c", &x, &c);
            update(1, x, getnum(c));
        }
        else
        {
            scanf("%d %d", &x, &y);
            SegTree tmp = query(1, x, y);
            long long ans = 0;
            for (int i = 0; i < 16; i++)
            {
                ans = (ans + tmp.dat[i] * mul[i] % mod) % mod;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}