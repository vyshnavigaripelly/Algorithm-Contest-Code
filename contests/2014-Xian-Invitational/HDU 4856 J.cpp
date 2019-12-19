#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>

#define INF 0x3f3f3f3f

using namespace std;

const int dir[4][2] = {-1, 0, 1, 0, 0, -1, 0, 1};

int n, m;
int minstep;
int minS[1 << 16][16], d[20][20], vis[1 << 16][16];
vector<pair<int, int>> in, out;
char mp[20][20];

struct node
{
    int x, y, step;
    node(int x, int y, int step) : x(x), y(y), step(step) {}
};

int check(int x, int y)
{
    if (mp[x][y] != '#' && x > -1 && x < n && y > -1 && y < n)
        return 1;
    return 0;
}

int bfs(int sid, int eid)
{
    queue<node> q;
    q.push(node(out[sid].first, out[sid].second, 0));
    int used[20][20] = {0};
    used[out[sid].first][out[sid].second] = 1;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        if (now.x == in[eid].first && now.y == in[eid].second)
            return now.step;
        for (int i = 0; i < 4; i++)
        {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if (!used[dx][dy] && check(dx, dy))
            {
                q.push(node(dx, dy, now.step + 1));
                used[dx][dy] = 1;
            }
        }
    }
    return INF;
}

int dfs(int nowid, int nowdp)
{
    if (vis[nowdp][nowid])
        return minS[nowdp][nowid];
    if (nowdp == ((1 << m) - 1))
        return 0;
    vis[nowdp][nowid] = 1;
    int &res = minS[nowdp][nowid];
    res = INF;
    for (int i = 0; i < n; i++)
    {
        if ((1 << i) & nowdp || i == nowid)
            continue;
        int tar = nowdp | (1 << i);
        res = min(dfs(i, tar) + d[nowid][i], res);
    }
    return res;
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        in.clear();
        out.clear();
        int sx, sy, ex, ey;
        for (int i = 0; i < n; i++)
            scanf("%s", &mp[i]);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &sx, &sy, &ex, &ey);
            in.push_back(make_pair(sx - 1, sy - 1));
            out.push_back(make_pair(ex - 1, ey - 1));
        }
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < i; j++)
            {
                d[i][j] = bfs(i, j);
                d[j][i] = bfs(j, i);
            }
        }
        int ans = INF;
        memset(vis, 0, sizeof(vis));
        for (int i = 0; i < m; i++)
        {
            minstep = dfs(i, 1 << i);
            ans = min(ans, minstep);
        }
        if (ans == INF)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}