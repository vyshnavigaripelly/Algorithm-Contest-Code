#include <iostream>
#include <cmath>

using namespace std;

const int N = 2e5 + 7;
const int H = 1e5 + 7;
const double eps = 1e-8;

int arr[N], rt[N];
long long presum[N];

struct ChairmanTree
{
    int tot = 0;

    struct Node
    {
        int l, r;
        long long sum, cnt;
    } tr[N * 24];

    void pushup(int root)
    {
        tr[root].cnt = tr[tr[root].l].cnt + tr[tr[root].r].cnt;
        tr[root].sum = tr[tr[root].l].sum + tr[tr[root].r].sum;
    }

    int build(int l, int r)
    {
        int root = ++tot;
        if (l == r)
            return root;
        int mid = (l + r) >> 1;
        tr[root].l = build(l, mid);
        tr[root].r = build(mid + 1, r);
        return root;
    }

    int update(int pre, int l, int r, long long val)
    {
        int root = ++tot;
        tr[root] = tr[pre];
        if (l == r)
        {
            tr[root].cnt++;
            tr[root].sum += val;
            return root;
        }
        int mid = (l + r) >> 1;
        if (val <= mid)
            tr[root].l = update(tr[pre].l, l, mid, val);
        else
            tr[root].r = update(tr[pre].r, mid + 1, r, val);
        pushup(root);
        return root;
    }

    long long querycnt(int u, int v, int l, int r, int ql, int qr)
    {
        if (qr < ql)
            return 0;
        if (l >= ql && r <= qr)
        {
            return tr[v].cnt - tr[u].cnt;
        }
        int mid = (l + r) >> 1;
        long long ans = 0;
        if (ql <= mid)
            ans += querycnt(tr[u].l, tr[v].l, l, mid, ql, qr);
        if (qr > mid)
            ans += querycnt(tr[u].r, tr[v].r, mid + 1, r, ql, qr);
        return ans;
    }

    long long querysum(int u, int v, int l, int r, int ql, int qr)
    {
        if (qr < ql)
            return 0;
        if (l >= ql && r <= qr)
        {
            return tr[v].sum - tr[u].sum;
        }
        int mid = (l + r) >> 1;
        long long ans = 0;
        if (ql <= mid)
            ans += querysum(tr[u].l, tr[v].l, l, mid, ql, qr);
        if (qr > mid)
            ans += querysum(tr[u].r, tr[v].r, mid + 1, r, ql, qr);
        return ans;
    }
} seg;

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        presum[i] = presum[i - 1] + arr[i];
    }
    rt[0] = seg.build(1, H);
    for (int i = 1; i <= n; i++)
    {
        rt[i] = seg.update(rt[i - 1], 1, H, arr[i]);
    }
    while (q--)
    {
        int l, r, x, y;
        scanf("%d %d %d %d", &l, &r, &x, &y);
        double sumh = presum[r] - presum[l - 1];
        double resth = sumh / y * (y - x);
        double ansl = 0, ansr = H + 5;
        while (ansr - ansl > eps)
        {
            double ansm = (ansl + ansr) / 2;
            double cnt = seg.querycnt(rt[l - 1], rt[r], 1, H, floor(ansm) + 1, H);
            double sum = seg.querysum(rt[l - 1], rt[r], 1, H, 1, floor(ansm));
            double cur = cnt * ansm + sum;
            if (cur < resth)
                ansl = ansm;
            else
                ansr = ansm;
        }
        printf("%.10f\n", ansl);
    }
    return 0;
}