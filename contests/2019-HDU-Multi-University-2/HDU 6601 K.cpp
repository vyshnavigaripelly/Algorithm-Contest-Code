#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <deque>

using namespace std;

const int N = 1e5 + 7;

int tot = 0;
long long arr[N], hsh[N];
int tr[N], L[N << 5], R[N << 5];
long long sum[N << 5];

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
    while (~scanf("%d %d", &n, &q))
    {
        tot = 0;
        memset(tr, 0, sizeof(tr));
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
            int x, y;
            scanf("%d %d", &x, &y);
            long long ans = -1;
            deque<long long> que;
            for (int i = 1; i <= min(50, y - x + 1); i++)
            {
                que.push_back(hsh[query(tr[x - 1], tr[y], 1, m, y - x + 1 - i + 1)]);
                if (que.size() >= 3)
                {
                    if (que[1] + que[2] > que[0])
                    {
                        ans = que[0] + que[1] + que[2];
                        break;
                    }
                    else
                    {
                        que.pop_front();
                    }
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}