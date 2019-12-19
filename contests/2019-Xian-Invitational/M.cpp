#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <map>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

long long n, m, C, D, E, lv, d[N], inq[N], bcj[N], flag;
vector<pair<int, int>> mp[N];
queue<pair<int, int>> q; // <current point, count of edge>

int find(int x)
{
    if (bcj[x] < 0)
        return x;
    return bcj[x] = find(bcj[x]);
}

int bfs()
{
    while (!q.empty())
    {
        q.pop();
    }
    memset(d, 0x3f, sizeof(d));
    d[1] = 0;
    q.push({1, 0});
    while (!q.empty())
    {
        pair<int, int> now = q.front();
        q.pop();
        if (now.first == n)
            return 1;
        for (int i = 0; i < mp[now.first].size(); i++)
        {
            int v = mp[now.first][i].first, w = mp[now.first][i].second;
            if (d[v] > now.second + 1 && now.second + 1 <= lv * E && w <= lv * D)
            {
                d[v] = now.second + 1;
                q.push({v, now.second + 1});
            }
        }
    }
    return 0;
}

int main()
{
    memset(bcj, -1, sizeof(bcj));
    long long u, v, w, maxw = -1;
    scanf("%lld %lld %lld %lld %lld", &n, &m, &C, &D, &E);
    for (int i = 0; i < m; i++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        maxw = max(maxw, w);
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
        int fu = find(u), fv = find(v);
        if (fu != fv)
            bcj[fu] = fv;
    }
    if (find(1) != find(n))
    {
        puts("-1");
        return 0;
    }
    long long l = 1, r = max(m * 10, maxw * 10), INF = 0x3f3f3f3f3f3f3f3f;
    long long ans = INF;
    while (l < r)
    {
        lv = (l + r) / 2;
        if (bfs())
        {
            r = lv;
            ans = min(ans, lv * C);
        }
        else
        {
            l = lv + 1;
        }
    }
    lv = l;
    if (bfs())
    {
        ans = min(ans, lv * C);
    }
    if (ans == INF)
    {
        ans = -1;
    }
    printf("%lld\n", ans);
    return 0;
}