#include <iostream>
#include <vector>

using namespace std;

const int N = 100007;

int n, m;
int arr[N], fa[N], dep[N];
vector<int> tree[N];

void dfs(int u, int pre, int deep)
{
    dep[u] = deep;
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if (v == pre)
            continue;
        fa[v] = u;
        dfs(v, u, deep + 1);
    }
}

long long solve(int s, int t, int a, int b)
{
    long long ans = 0;
    while (dep[s] > dep[t])
    {
        if (arr[s] <= b && arr[s] >= a)
            ans += arr[s];
        s = fa[s];
    }
    while (dep[t] > dep[s])
    {
        if (arr[t] <= b && arr[t] >= a)
            ans += arr[t];
        t = fa[t];
    }
    while (s != t)
    {
        if (arr[s] <= b && arr[s] >= a)
            ans += arr[s];
        if (arr[t] <= b && arr[t] >= a)
            ans += arr[t];
        s = fa[s];
        t = fa[t];
    }
    if (arr[s] <= b && arr[s] >= a)
        ans += arr[s];
    return ans;
}

int main()
{
    while (~scanf("%d %d", &n, &m))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            tree[i].clear();
        }
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            tree[u].push_back(v);
            tree[v].push_back(u);
        }
        dfs(1, -1, 1);
        for (int i = 0; i < m; i++)
        {
            int s, t, a, b;
            scanf("%d %d %d %d", &s, &t, &a, &b);
            printf("%lld %c", solve(s, t, a, b), i != m - 1 ? ' ' : '\n');
        }
    }
    return 0;
}