#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;

struct SegTree
{
    int ls, rs;
    int dat;
} tr[N * 4 * 100];

vector<int> edge[N], factor[N];
int tot, now;
int arr[N], ans[N], root[N];

void insert(int &root, int l, int r, int pos)
{
    if (root == 0)
    {
        root = ++tot;
        tr[root].ls = tr[root].rs = 0;
        tr[root].dat = -1;
    }
    if (l == r)
    {
        tr[root].dat = pos;
        return;
    }
    int mid = (l + r) >> 1;
    if (pos <= mid)
    {
        insert(tr[root].ls, l, mid, pos);
    }
    else
    {
        insert(tr[root].rs, mid + 1, r, pos);
    }
}

int merge(int p, int q, int l, int r)
{
    if (p == 0 || q == 0)
    {
        return p + q;
    }
    if (l == r)
    {
        ans[now] = max(ans[now], l);
        return p;
    }
    int mid = (l + r) >> 1;
    tr[p].ls = merge(tr[p].ls, tr[q].ls, l, mid);
    tr[p].rs = merge(tr[p].rs, tr[q].rs, mid + 1, r);
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
        now = u;
        root[u] = merge(root[u], root[to], 1, N);
    }
}

int main()
{
    memset(ans, -1, sizeof(ans));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; i * j <= N; j++)
        {
            factor[i * j].push_back(i);
        }
    }
    tot = 0;
    int n;
    scanf("%d", &n);
    for (int i = 2; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        edge[i].push_back(x);
        edge[x].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        for (int j = 0; j < factor[arr[i]].size(); j++)
        {
            insert(root[i], 1, N, factor[arr[i]][j]);
        }
    }
    dfs(1, -1);
    for (int i = 1; i <= n; i++)
    {
        printf("%d\n", ans[i]);
    }
    return 0;
}