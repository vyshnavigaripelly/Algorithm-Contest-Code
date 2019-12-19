#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x, y, moves;
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
};

int vis[500][500];
queue<Point> q;

int bfs(Point start, Point end, int size)
{
    int dir[8][2] = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
    vis[start.x][start.y] = 1;
    q.push(start);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], cur.moves + 1};
            if (next.x < 0 || next.x > size - 1 || next.y < 0 || next.y > size - 1)
            {
                continue;
            }
            if (vis[next.x][next.y] == 0)
            {
                vis[next.x][next.y] = 1;
                q.push(next);
            }
            if (next == end)
            {
                return next.moves;
            }
        }
    }
    return -1;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        int l, sx, sy, ex, ey;
        scanf("%d %d %d %d %d", &l, &sx, &sy, &ex, &ey);
        Point start = {sx, sy, 0}, end = {ex, ey, -1};
        if (start == end)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", bfs(start, end, l));
        }
    }
    return 0;
}
