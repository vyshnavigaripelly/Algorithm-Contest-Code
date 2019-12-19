#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 1e6 + 5;
const int maxdigit = 4;

int arr[N];

struct SegTree
{
    int l, r;
    int dig[maxdigit]; // 区间各位上有多少个1
    int lazyset[maxdigit]; // 懒惰标记，向下赋值，为-1表示区间没有被完全覆盖
    int lazyxor[maxdigit]; // 懒惰标记，异或，为1表示区间需要被反转
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
        tr[lson].lazyxor[pos] = tr[rson].lazyxor[pos] = 0; // 子节点也被完全覆盖，因此不用异或
    }
    if (tr[root].lazyxor[pos]) // 区间没被完全覆盖且需要异或
    {
        tr[lson].dig[pos] = (tr[lson].r - tr[lson].l + 1) - tr[lson].dig[pos];
        tr[rson].dig[pos] = (tr[rson].r - tr[rson].l + 1) - tr[rson].dig[pos];
        tr[lson].lazyxor[pos] ^= 1;
        tr[rson].lazyxor[pos] ^= 1;
        tr[root].lazyxor[pos] = 0;
    }
}

void build(int root, int l, int r)
{
    tr[root].l = l;
    tr[root].r = r;
    memset(tr[root].dig, 0, sizeof(tr[root].dig));
    memset(tr[root].lazyset, -1, sizeof(tr[root].lazyset));
    memset(tr[root].lazyxor, 0, sizeof(tr[root].lazyxor));
    if (l == r)
    {
        for (int i = 0; i < maxdigit; i++)
        {
            if (arr[l] & (1LL << i))
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
        if (val == -1) // 异或
        {
            tr[root].dig[pos] = (tr[root].r - tr[root].l + 1) - tr[root].dig[pos];
            if (tr[root].lazyset[pos] != -1) // 如果被完全覆盖则对覆盖标记取反
                tr[root].lazyset[pos] ^= 1;
            else
                tr[root].lazyxor[pos] ^= 1; // 否则对异或标记取反
        }
        else
        {
            tr[root].dig[pos] = (tr[root].r - tr[root].l + 1) * val;
            tr[root].lazyset[pos] = val;
            tr[root].lazyxor[pos] = 0; // 区间被完全覆盖，不用异或
        }
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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
            scanf("%d", &arr[i]);
        build(1, 1, n);
        while (m--)
        {
            char op[7];
            int l, r, val;
            scanf("%s", op);
            if (op[0] == 'S') // 查询区间和
            {
                scanf("%d %d", &l, &r);
                l++, r++;
                int ans = 0;
                for (int i = 0; i < maxdigit; i++)
                    ans += query(1, l, r, i) * (1LL << i);
                printf("%d\n", ans);
            }
            else
            {
                scanf("%d %d %d", &val, &l, &r);
                l++, r++;
                if (op[0] == 'A') // 按位且
                {
                    for (int i = 0; i < maxdigit; i++)
                    {
                        if ((val & (1LL << i)) == 0)
                            update(1, l, r, i, 0);
                    }
                }
                else if (op[0] == 'O') // 按位或
                {
                    for (int i = 0; i < maxdigit; i++)
                    {
                        if (val & (1LL << i))
                            update(1, l, r, i, 1);
                    }
                }
                else if (op[0] == 'X') // 按位异或
                {
                    for (int i = 0; i < maxdigit; i++)
                    {
                        if (val & (1LL << i))
                            update(1, l, r, i, -1);
                    }
                }
            }
        }
    }
    return 0;
}