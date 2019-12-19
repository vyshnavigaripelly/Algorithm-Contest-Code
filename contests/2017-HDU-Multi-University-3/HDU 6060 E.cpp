#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>

using namespace std;

vector<pair<int, int>> tree[1000007];

int n, k, u, v, w;
int vis[1000007], size[1000007];
long long ans, d[1000007];

void dfs(int u, long long weight)
{
    size[u] = 1;
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i].first, w = tree[u][i].second;
        if (!vis[v])
        {
            vis[v] = 1;
            d[v] = w;
            dfs(v, weight + w);
            size[u] += size[v];
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &k))
    {
        for (int i = 1; i <= n; i++)
        {
            vis[i] = 0;
            tree[i].clear();
        }
        ans = 0;
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            tree[u].push_back(make_pair(v, w));
            tree[v].push_back(make_pair(u, w));
        }
        vis[1] = 1;
        dfs(1, 0);
        for (int i = 2; i <= n; i++)
        {
            ans = ans + d[i] * min(k, size[i]);
        }
        printf("%lld\n", ans);
    }
    return 0;
}