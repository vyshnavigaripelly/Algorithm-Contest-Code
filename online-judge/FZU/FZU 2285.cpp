#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x, y, step;
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y;
    }
};

const int MAXSIZE = 1005;

int vis[MAXSIZE][MAXSIZE];
char map[MAXSIZE][MAXSIZE];
queue<Point> q;

int bfs(Point start, Point end)
{
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    vis[start.x][start.y] = 1;
    q.push(start);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        if (cur == end)
        {
            return cur.step;
        }
        for (int i = 0; i < 4; i++)
        {
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], cur.step + 1};
            if (map[next.x][next.y] == '#')
            {
                continue;
            }
            if (vis[next.x][next.y] == 0)
            {
                vis[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
    return -1;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(map, '#', sizeof(map));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        int sx, sy, ex, ey;
        for (int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= n; j++)
            {
                scanf("%c", &map[i][j]);
                if (map[i][j] == 'S')
                {
                    sx = i;
                    sy = j;
                }
                if (map[i][j] == 'E')
                {
                    ex = i;
                    ey = j;
                }
            }
        }
        Point start = {sx, sy, 0}, end = {ex, ey, -1};
        if (start == end)
        {
            printf("0\n");
        }
        else
        {
            printf("%d\n", bfs(start, end));
        }
    }
    return 0;
}
