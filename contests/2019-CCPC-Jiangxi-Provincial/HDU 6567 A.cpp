#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

vector<int> tree[N];
int n, n1, n2, cnt, pos, flag, siz[N], vis[N];
long long ans;

void dfs(int u)
{
    vis[u] = 1;
    n1++;
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if (vis[v])
            continue;
        dfs(v);
    }
}

void dfsWeight(int u, int fa)
{
    siz[u] = 1;
    int max_part = 0;
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if (v == fa)
            continue;
        dfsWeight(v, u);
        siz[u] += siz[v];
        max_part = max(max_part, siz[v]);
    }
    max_part = max(max_part, (flag ? n2 : n1) - siz[u]);
    if (max_part < cnt)
    {
        cnt = max_part;
        pos = u;
    }
}

void dfsAns(int u, int fa)
{
    siz[u] = 1;
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        if (v == fa)
            continue;
        dfsAns(v, u);
        siz[u] += siz[v];
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n - 2; i++)
    {
        int u, v;
        scanf("%d%d", &u, &v);
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    int st = 1;
    dfs(1);
    n2 = n - n1;
    for (int i = 2; i <= n; i++)
    {
        if (!vis[i])
        {
            st = i;
            break;
        }
    }
    cnt = 0x3f3f3f3f;
    dfsWeight(1, -1);
    flag = 1;
    int weight1 = pos;
    cnt = 0x3f3f3f3f;
    dfsWeight(st, -1);
    int weight2 = pos;
    tree[weight1].push_back(weight2);
    tree[weight2].push_back(weight1);
    dfsAns(1, -1);
    for (int i = 1; i <= n; i++)
    {
        ans += (long long)(n - siz[i]) * siz[i];
    }
    cout << ans << endl;
    return 0;
}