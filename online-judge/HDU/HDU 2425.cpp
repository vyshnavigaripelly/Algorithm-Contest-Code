#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x, y, time;
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
    bool operator<(const Point &p) const
    {
        return time > p.time;
    }
};

const int MAXSIZE = 30;

int vis[MAXSIZE][MAXSIZE];
char map[MAXSIZE][MAXSIZE];
priority_queue<Point> q;

int bfs(Point start, Point end, int vP, int vS, int vT)
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vis[start.x][start.y] = 1;
    q.push(start);
    while (!q.empty())
    {
        Point cur = q.top();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], -1};
            if (map[next.x][next.y] == '@')
            {
                continue;
            }
            if (!vis[next.x][next.y])
            {
                vis[next.x][next.y] = 1;
                if (map[next.x][next.y] == '#') // path
                {
                    next.time = cur.time + vP;
                }
                else if (map[next.x][next.y] == '.') // sand
                {
                    next.time = cur.time + vS;
                }
                else if (map[next.x][next.y] == 'T') // tree
                {
                    next.time = cur.time + vT;
                }
                q.push(next);
            }
            if (next == end)
            {
                return next.time;
            }
        }
    }
    return -1;
}

int main()
{
    int r, c, cas = 1;
    while (cin >> r >> c)
    {
        memset(map, '@', sizeof(map));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        int vP, vS, vT;
        cin >> vP >> vS >> vT;
        for (int i = 1; i <= r; i++)
        {
            for (int j = 1; j <= c; j++)
            {
                cin >> map[i][j];
            }
        }
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;
        Point start = {sx + 1, sy + 1, 0}, end = {ex + 1, ey + 1, -1};
        cout << "Case " << cas << ": ";
        if (start == end)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << bfs(start, end, vP, vS, vT) << endl;
        }
        cas++;
    }
    return 0;
}
