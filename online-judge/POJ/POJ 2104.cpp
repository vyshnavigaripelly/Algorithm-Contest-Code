#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

int tot = 0;
int arr[N], hsh[N];
int tr[N], L[N << 5], R[N << 5];
int sum[N << 5];

int build(int l, int r)
{
    int rt = ++tot;
    int mid = (l + r) >> 1;
    if (l < r)
    {
        L[rt] = build(l, mid);
        R[rt] = build(mid + 1, r);
    }
    return rt;
}

int update(int pre, int l, int r, int x)
{
    int rt = ++tot;
    L[rt] = L[pre];
    R[rt] = R[pre];
    sum[rt] = sum[pre] + 1;
    int mid = (l + r) >> 1;
    if (l < r)
    {
        if (x <= mid)
            L[rt] = update(L[pre], l, mid, x);
        else
            R[rt] = update(R[pre], mid + 1, r, x);
    }
    return rt;
}

int query(int u, int v, int l, int r, int k)
{
    if (l == r)
        return l;
    int x = sum[L[v]] - sum[L[u]];
    int mid = (l + r) >> 1;
    if (x >= k)
        return query(L[u], L[v], l, mid, k);
    else
        return query(R[u], R[v], mid + 1, r, k - x);
}

int main()
{
    int n, q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        hsh[i] = arr[i];
    }
    sort(hsh + 1, hsh + 1 + n);
    int m = unique(hsh + 1, hsh + 1 + n) - (hsh + 1);
    tr[0] = build(1, m);
    for (int i = 1; i <= n; i++)
    {
        arr[i] = lower_bound(hsh + 1, hsh + 1 + m, arr[i]) - hsh;
        tr[i] = update(tr[i - 1], 1, m, arr[i]);
    }
    while (q--)
    {
        int x, y, k;
        scanf("%d %d %d", &x, &y, &k);
        int pos = query(tr[x - 1], tr[y], 1, m, k);
        printf("%d\n", hsh[pos]);
    }
    return 0;
}