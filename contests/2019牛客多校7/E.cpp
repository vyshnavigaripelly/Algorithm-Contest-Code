#include <iostream>
#include <algorithm>

using namespace std;

const int N = 4e5 + 7;

long long x[N], y[N], l[N], r[N];
long long dis[2 * N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct
    {
        int l, r;
        long long cnt; // how many numbers in [dis[l], dis[r + 1])
        long long dat; // how many times add to [dis[l], dis[r + 1])
        long long lazyadd;
        long long len;
    } tr[2 * N * 4];

    void pushup(int root)
    {
        tr[root].cnt = tr[lson].cnt + tr[rson].cnt;
        tr[root].len = tr[lson].len + tr[rson].len;
    }

    void pushdown(int root)
    {
        if (tr[root].lazyadd != 0)
        {
            tr[lson].lazyadd += tr[root].lazyadd;
            tr[rson].lazyadd += tr[root].lazyadd;
            tr[lson].dat += tr[root].lazyadd;
            tr[rson].dat += tr[root].lazyadd;
            tr[lson].cnt += tr[root].lazyadd * tr[lson].len;
            tr[rson].cnt += tr[root].lazyadd * tr[rson].len;
            tr[root].lazyadd = 0;
        }
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 0, 0, 0, 0};
        if (l == r)
        {
            tr[root].len = dis[l + 1] - dis[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(root);
    }

    void update(int root, int l, int r)
    {
        if (tr[root].l >= l && tr[root].r <= r)
        {
            tr[root].dat++;
            tr[root].lazyadd++;
            tr[root].cnt += tr[root].len;
            return;
        }
        pushdown(root);
        int mid = (tr[root].l + tr[root].r) >> 1;
        if (l <= mid)
            update(lson, l, r);
        if (r > mid)
            update(rson, l, r);
        pushup(root);
    }

    long long query(int root, long long k)
    {
        if (tr[root].l == tr[root].r)
        {
            return dis[tr[root].l] + (k - 1) / tr[root].dat;
        }
        pushdown(root);
        long long cntl = tr[lson].cnt;
        if (k > cntl)
            return query(rson, k - cntl);
        else
            return query(lson, k);
    }
} seg;

int main()
{
    int n;
    long long xa, xb, xc, xm, ya, yb, yc, ym;
    scanf("%d", &n);
    scanf("%lld %lld %lld %lld %lld %lld", &x[1], &x[2], &xa, &xb, &xc, &xm);
    scanf("%lld %lld %lld %lld %lld %lld", &y[1], &y[2], &ya, &yb, &yc, &ym);
    for (int i = 3; i <= n; i++)
    {
        x[i] = (xa * x[i - 1] + xb * x[i - 2] + xc) % xm;
        y[i] = (ya * y[i - 1] + yb * y[i - 2] + yc) % ym;
    }
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        l[i] = min(x[i], y[i]) + 1;
        r[i] = max(x[i], y[i]) + 1;
        dis[++tot] = l[i];
        dis[++tot] = r[i] + 1;
    }
    sort(dis + 1, dis + 1 + tot);
    tot = unique(dis + 1, dis + 1 + tot) - (dis + 1);
    seg.build(1, 1, tot - 1);
    long long cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        cnt += r[i] - l[i] + 1;
        int L = lower_bound(dis + 1, dis + 1 + tot, l[i]) - dis;
        int R = lower_bound(dis + 1, dis + 1 + tot, r[i] + 1) - dis;
        seg.update(1, L, R - 1);
        printf("%lld\n", seg.query(1, (1 + cnt) / 2));
    }
    return 0;
}