#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <cstdio>

const int mod = 1e9 + 7;

using namespace std;

vector<pair<int, int>> mp[100007];
int vis[100007], red[100007], ok[100007], cnt, num;

long long fpow(long long a, long long b, long long mod = mod)
{
    long long s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return s;
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = 0; i < mp[now].size(); i++)
        {
            int v = mp[now][i].first, w = mp[now][i].second;
            if (w == 0 && vis[v] == 0)
            {
                vis[v] = 1;
                cnt++;
                q.push(v);
            }
        }
    }
}

int main()
{
    int u, v, w, n, k;
    long long ans = 0;
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d %d %d", &u, &v, &w);
        mp[u].push_back(make_pair(v, w));
        mp[v].push_back(make_pair(u, w));
        if (w == 0)
        {
            ok[u] = ok[v] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i] && ok[i])
        {
            cnt = 1;
            bfs(i);
            red[num] = cnt;
            num++;
        }
    }
    ans = fpow(n, k);
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            ans--;
        }
    }
    if (ans < 0)
    {
        ans += mod;
    }
    for (int i = 0; i < num; i++)
    {
        long long tmp = fpow(red[i], k);
        ans -= tmp;
        if (ans < 0)
        {
            ans += mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}