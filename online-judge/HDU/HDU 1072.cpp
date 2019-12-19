#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x, y, explodetime, time;
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
};

const int MAXSIZE = 10;

int vis[MAXSIZE][MAXSIZE];
int map[MAXSIZE][MAXSIZE];
queue<Point> q;

int bfs(Point start, Point end)
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    q.push(start);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], cur.explodetime - 1, cur.time + 1};
            if (map[next.x][next.y] == 0)
            {
                continue;
            }
            if (next.explodetime == 0)
            {
                continue;
            }
            if (map[next.x][next.y] == 4) // bomb reset equipment
            {
                next.explodetime = 6;
                map[next.x][next.y] = 0;
            }
            q.push(next);
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
    int t;
    cin >> t;
    while (t--)
    {
        memset(map, 0, sizeof(map));
        while (!q.empty())
        {
            q.pop();
        }
        int n, m;
        cin >> n >> m;
        Point start, end;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == 2)
                {
                    start = {i, j, 6, 0};
                }
                if (map[i][j] == 3)
                {
                    end = {i, j, -1, -1};
                }
            }
        }
        if (start == end)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << bfs(start, end) << endl;
        }
    }
    return 0;
}
