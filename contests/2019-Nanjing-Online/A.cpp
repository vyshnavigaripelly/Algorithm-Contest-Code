#include <bits/stdc++.h>

using namespace std;

struct node
{
    long long op, x, y;
    long long t, id, A;
    node() {}
    node(long long op, long long x, long long y, long long t, long long id, long long A) : op(op), x(x), y(y), t(t), id(id), A(A) {}
} qu[800005], newq[800005];

long long n, m, q;
long long c[2000005];
long long ans[2000005];
long long tot, top;

bool cmp(node a, node b)
{
    if (a.x == b.x && a.y == b.y)
        return a.op < b.op;
    if (a.x == b.x)
        return a.y < b.y;
    return a.x < b.x;
}

void add(long long i, long long k)
{
    while (i <= n)
    {
        c[i] += k;
        i += (i & -i);
    }
}

long long sum(long long i)
{
    long long ans = 0;
    while (i)
    {
        ans += c[i];
        i -= (i & -i);
    }
    return ans;
}

void solve(long long l, long long r)
{
    if (l == r)
        return;
    long long mid = (l + r) >> 1;
    for (long long i = l; i <= r; i++)
    {
        if (qu[i].op == 1 && qu[i].t <= mid)
        {
            add(qu[i].y, qu[i].A);
        }
        if (qu[i].op == 2 && qu[i].t > mid)
        {
            ans[qu[i].id] += sum(qu[i].y) * qu[i].A;
        }
    }
    for (long long i = l; i <= r; i++)
    {
        if (qu[i].op == 1 && qu[i].t <= mid)
        {
            add(qu[i].y, -qu[i].A);
        }
    }
    long long l1 = l, l2 = mid + 1;
    for (long long i = l; i <= r; i++)
    {
        if (qu[i].t > mid)
        {
            newq[l2++] = qu[i];
        }
        if (qu[i].t <= mid)
        {
            newq[l1++] = qu[i];
        }
    }
    for (long long i = l; i <= r; i++)
    {
        qu[i] = newq[i];
    }
    solve(l, mid);
    solve(mid + 1, r);
}

long long digit(long long x)
{
    long long ans = 0;
    while (x)
    {
        ans += x % 10;
        x /= 10;
    }
    return ans;
}

int main()
{
    long long t;
    scanf("%lld", &t);
    while (t--)
    {
        tot = 0, top = 0;
        scanf("%lld%lld%lld", &n, &m, &q);
        for (long long i = 1; i <= n; i++)
            add(i, 0);
        for (long long i = 0; i < m; i++)
        {
            long long x, y;
            scanf("%lld%lld", &x, &y);
            long long mi, ans;
            swap(x, y);
            long long I = n + 1 - y, J = n + 1 - x;
            mi = min(I, min(J, min(n - I + 1, n - J + 1)));
            if (I <= J)
                ans = mi * (4 * (n - 1) - 4 * mi) + 10 * mi - 4 * n - 3 + I + J;
            else
                ans = mi * (4 * n - 4 * mi) + 2 * mi + 1 - I - J;
            long long v = digit(ans);
            qu[tot] = node(1, x, y, tot, 0, v);
            tot++;
        }
        for (long long i = 0; i < q; i++)
        {
            long long x1, y1, x2, y2;
            scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);
            swap(x1, y1);
            swap(x2, y2);
            qu[tot] = node(2, x2, y2, tot, top, 1);
            tot++;
            qu[tot] = node(2, x1 - 1, y2, tot, top, -1);
            tot++;
            qu[tot] = node(2, x2, y1 - 1, tot, top, -1);
            tot++;
            qu[tot] = node(2, x1 - 1, y1 - 1, tot, top, 1);
            tot++;
            top++;
        }
        sort(qu, qu + tot, cmp);
        solve(0, tot - 1);
        for (long long i = 0; i < top; i++)
            printf("%lld\n", ans[i]);
        memset(ans, 0, (top + 1) * sizeof(long long));
        memset(c, 0, sizeof(c));
    }
    return 0;
}