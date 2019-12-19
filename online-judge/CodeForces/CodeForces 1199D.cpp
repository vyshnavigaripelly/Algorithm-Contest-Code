#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 7, inf = ~0U >> 1;

#define lson (root << 1)
#define rson (root << 1 | 1)

int n, m, i, arr[N], op, c, d, p, ans;
int len[N << 2], cma[N << 2], cmi[N << 2], ma[N << 2], ma2[N << 2], mi[N << 2], mi2[N << 2], tma[N << 2], tmi[N << 2], ta[N << 2];
long long sum[N << 2], ret;

void tagmi(int root, int p)
{
    tmi[root] += p;
    if (ma[root] == mi[root])
    {
        ma[root] += p;
        mi[root] = ma[root];
        sum[root] = 1LL * ma[root] * len[root];
        return;
    }
    mi[root] += p;
    if (cma[root] + cmi[root] == len[root])
        ma2[root] += p;
    sum[root] += 1LL * p * cmi[root];
}

void taga(int root, int p)
{
    ta[root] += p;
    ma[root] += p;
    mi[root] += p;
    if (ma2[root] != -inf)
        ma2[root] += p;
    if (mi2[root] != inf)
        mi2[root] += p;
    sum[root] += 1LL * p * len[root];
}

void pushdown(int root)
{
    if (tmi[root])
    {
        if (mi[lson] < mi[rson])
            tagmi(lson, tmi[root]);
        else if (mi[lson] > mi[rson])
            tagmi(rson, tmi[root]);
        else
        {
            tagmi(lson, tmi[root]);
            tagmi(rson, tmi[root]);
        }
        tmi[root] = 0;
    }
    if (ta[root])
    {
        taga(lson, ta[root]);
        taga(rson, ta[root]);
        ta[root] = 0;
    }
}

void pushup(int root)
{
    sum[root] = sum[lson] + sum[rson];
    if (ma[lson] > ma[rson])
    {
        ma[root] = ma[lson];
        ma2[root] = max(ma2[lson], ma[rson]);
        cma[root] = cma[lson];
    }
    else if (ma[lson] < ma[rson])
    {
        ma[root] = ma[rson];
        ma2[root] = max(ma[lson], ma2[rson]);
        cma[root] = cma[rson];
    }
    else
    {
        ma[root] = ma[lson];
        ma2[root] = max(ma2[lson], ma2[rson]);
        cma[root] = cma[lson] + cma[rson];
    }
    if (mi[lson] < mi[rson])
    {
        mi[root] = mi[lson];
        mi2[root] = min(mi2[lson], mi[rson]);
        cmi[root] = cmi[lson];
    }
    else if (mi[lson] > mi[rson])
    {
        mi[root] = mi[rson];
        mi2[root] = min(mi[lson], mi2[rson]);
        cmi[root] = cmi[rson];
    }
    else
    {
        mi[root] = mi[lson];
        mi2[root] = min(mi2[lson], mi2[rson]);
        cmi[root] = cmi[lson] + cmi[rson];
    }
}

void build(int root, int l, int r)
{
    len[root] = r - l + 1;
    if (l == r)
    {
        ma[root] = mi[root] = sum[root] = arr[l];
        ma2[root] = -inf;
        mi2[root] = inf;
        cma[root] = cmi[root] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(root);
}

void change(int root, int l, int r)
{
    if (c <= l && r <= d)
    {
        taga(root, p);
        return;
    }
    pushdown(root);
    int mid = (l + r) >> 1;
    if (c <= mid)
        change(lson, l, mid);
    if (d > mid)
        change(rson, mid + 1, r);
    pushup(root);
}

void changemin(int root, int l, int r)
{
    if (c <= l && r <= d)
    {
        if (mi[root] >= p)
            return;
        if (mi2[root] > p)
        {
            tagmi(root, p - mi[root]);
            return;
        }
    }
    pushdown(root);
    int mid = (l + r) >> 1;
    if (c <= mid)
        changemin(lson, l, mid);
    if (d > mid)
        changemin(rson, mid + 1, r);
    pushup(root);
}

void query(int root, int l, int r)
{
    if (c <= l && r <= d)
    {
        ret += sum[root];
        return;
    }
    pushdown(root);
    int mid = (l + r) >> 1;
    if (c <= mid)
        query(lson, l, mid);
    if (d > mid)
        query(rson, mid + 1, r);
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &arr[i]);
    build(1, 1, n);
    scanf("%d", &m);
    while (m--)
    {
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d %d", &c, &p);
            d = c;
            ret = 0;
            query(1, 1, n);
            p = p - ret;
            change(1, 1, n);
        }
        else if (op == 2)
        {
            scanf("%d", &p);
            c = 1;
            d = n;
            changemin(1, 1, n);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        ret = 0;
        c = d = i;
        query(1, 1, n);
        printf("%lld ", ret);
    }
    return 0;
}