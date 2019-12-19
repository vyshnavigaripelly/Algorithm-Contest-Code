#include <bits/stdc++.h>

using namespace std;

const long long INF = 0x3f3f3f3f;
const int maxn = 2e5 + 5;

vector<int> G[maxn];
bool mon[maxn];
int vis[maxn];
int arr[maxn], len;
int cnt[maxn], group;

long long dfs(int u, int fa)
{
    long long sum = 0;
    for (int i = 0; i < G[u].size(); i++)
    {
        int &v = G[u][i];
        if (mon[v] || vis[v] == 1)
            continue;
        if (vis[v] > 1)
        {
            sum += cnt[vis[v]];
            continue;
        }
        long long num = 0;
        if (fa == 0)
        {
            vis[v] = ++group;
        }
        else
        {
            vis[v] = vis[u];
        }
        num++;
        num += dfs(v, u);
        sum += num;
        if (fa == 0)
        {
            cnt[vis[v]] = num;
        }
    }
    return sum;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        for (size_t i = 0; i < maxn; i++)
        {
            G[i].clear();
            mon[i] = 0;
            vis[i] = 0;
            arr[i] = 0;
            cnt[i] = 0;
        }
        len = 0;
        group = 1;
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        for (size_t i = 0; i < m; i++)
        {
            int a, b;
            scanf("%d %d", &a, &b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        for (size_t i = 0; i < k; i++)
        {
            int a;
            scanf("%d", &a);
            mon[a] = 1;
        }
        double ans = 1;
        queue<int> q;
        q.push(1);
        vis[1] = 1;
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            for (int i = 0; i < G[u].size(); i++)
            {
                int &v = G[u][i];
                if (vis[v])
                    continue;
                vis[v] = 1;
                if (!mon[v])
                {
                    ans += 1;
                    q.push(v);
                }
                else
                    arr[len++] = v;
            }
        }
        double maxexp = 0;
        for (int i = 0; i < len; i++)
        {
            long long num = dfs(arr[i], 0);
            maxexp = max(num * 1.0 / G[arr[i]].size(), maxexp);
        }
        printf("%.8f\n", ans + maxexp);
    }
    return 0;
}