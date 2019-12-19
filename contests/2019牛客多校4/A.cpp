#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int N = 1e5 + 7;

int n, m, tarp, tarl = -1;
int d[N], query[N], flag;
vector<int> tree[N], q1, q2;

void dfs(int u, int fa)
{
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if (v == fa)
            continue;
        d[v] = d[u] + 1;
        dfs(v, u);
    }
}

int dfs1(int u, int fa)
{
    if (u == tarp)
    {
        if (d[u] == (tarl / 2))
        {
            q2.push_back(u);
        }
        if ((tarl & 1) && (d[u] == (tarl / 2 + 1)))
        {
            q2.push_back(u);
        }
        return 1;
    }
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if (v == fa)
            continue;
        if (dfs1(v, u))
        {
            if (d[u] == (tarl / 2))
            {
                q2.push_back(u);
            }
            if ((tarl & 1) && (d[u] == (tarl / 2 + 1)))
            {
                q2.push_back(u);
            }
            return 1;
        }
    }
    return 0;
}

int main()
{
    scanf("%d %d", &n, &m);
    if (m == 1)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    for (int i = 0; i < m; i++)
    {
        scanf("%d", &query[i]);
    }
    dfs(query[0], -1);
    int maxn = -1, pp;
    for (int i = 1; i < m; i++)
    {
        if (maxn < d[query[i]])
        {
            maxn = d[query[i]];
            pp = query[i];
        }
    }
    d[pp] = 0;
    dfs(pp, -1);
    for (int i = 0; i < m; i++)
    {
        if (tarl < d[query[i]])
        {
            tarl = d[query[i]];
            q1.clear();
        }
        if (tarl == d[query[i]])
        {
            q1.push_back(query[i]);
        }
    }
    int ans1 = 0x3f3f3f3f;
    for (int i = 0; i < q1.size(); i++)
    {
        q2.clear();
        tarp = q1[i];
        dfs1(pp, -1);
        for (int j = 0; j < q2.size(); j++)
        {
            int ans2 = -1;
            int now = q2[j];
            d[now] = 0;
            dfs(now, -1);
            for (int k = 0; k < m; k++)
            {
                ans2 = max(ans2, d[query[k]]);
            }
            ans1 = min(ans1, ans2);
        }
    }
    printf("%d\n", ans1);
    return 0;
}