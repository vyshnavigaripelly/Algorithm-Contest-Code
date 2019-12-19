#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;

struct SegTree
{
    int lc, rc;
    int size;
    long long sum, dat;
} tr[N * 18];

vector<int> edge[N];
int tot;
int arr[N], raw[N];
int rt[N];

void insert(int &root, int l, int r, int pos)
{
    root = ++tot;
    tr[root].lc = tr[root].rc = 0;
    tr[root].sum = tr[root].dat = raw[pos];
    tr[root].size = 1;
    if (l == r)
    {
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        insert(tr[root].lc, l, mid, pos);
    }
    else
    {
        insert(tr[root].rc, mid + 1, r, pos);
    }
}

int merge(int p, int q)
{
    if (p == 0 || q == 0)
    {
        return p + q;
    }
    if (tr[p].lc || tr[p].rc)
    {
        tr[p].lc = merge(tr[p].lc, tr[q].lc);
        tr[p].rc = merge(tr[p].rc, tr[q].rc);
        tr[p].size = tr[tr[p].lc].size + tr[tr[p].rc].size;
        tr[p].sum = tr[tr[p].lc].sum + tr[tr[p].rc].sum;
        tr[p].dat = tr[tr[p].lc].dat + tr[tr[p].rc].dat + tr[tr[p].lc].sum * tr[tr[p].rc].size;
    }
    else
    {
        tr[p].dat = tr[p].dat + tr[q].dat + tr[p].sum * tr[q].size;
        tr[p].sum += tr[q].sum;
        tr[p].size += tr[q].size;
    }
    return p;
}

void dfs(int u, int pre)
{
    for (int i = 0; i < edge[u].size(); i++)
    {
        int to = edge[u][i];
        if (to == pre)
        {
            continue;
        }
        dfs(to, u);
        merge(rt[u], rt[to]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        tot = 0;
        memset(tr, 0, sizeof(tr));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            edge[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            raw[i] = arr[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            edge[u].push_back(v);
            edge[v].push_back(u);
        }
        sort(raw + 1, raw + 1 + n);
        int cnt = unique(raw + 1, raw + 1 + n) - (raw + 1);
        for (int i = 1; i <= n; i++)
        {
            arr[i] = lower_bound(raw + 1, raw + 1 + cnt, arr[i]) - (raw + 1) + 1;
            insert(rt[i], 1, cnt, arr[i]);
        }
        dfs(1, -1);
        for (int i = 1; i <= n; i++)
        {
            printf("%lld ", tr[rt[i]].dat);
        }
        puts("");
    }
    return 0;
}