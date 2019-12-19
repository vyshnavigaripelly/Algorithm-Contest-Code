#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x, y, z, time;
    bool operator==(const Point &p) const
    {
        return x == p.x && y == p.y && z == p.z;
    }
};

int vis[60][60][60], map[60][60][60];
queue<Point> q;

int bfs(Point start, Point end, int maxtime)
{
    int dir[6][3] = {{0, 0, 1}, {0, 1, 0}, {1, 0, 0}, {0, 0, -1}, {0, -1, 0}, {-1, 0, 0}};
    vis[start.x][start.y][start.z] = 1;
    q.push(start);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 6; i++)
        {
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], cur.z + dir[i][2], cur.time + 1};
            if (map[next.x][next.y][next.z] != 0)
            {
                continue;
            }
            if (next.time > maxtime)
            {
                continue;
            }
            if (!vis[next.x][next.y][next.z])
            {
                vis[next.x][next.y][next.z] = 1;
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
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(map, -1, sizeof(map));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        int a, b, c, maxtime;
        scanf("%d %d %d %d", &a, &b, &c, &maxtime);
        for (int i = 1; i <= a; i++)
        {
            for (int j = 1; j <= b; j++)
            {
                for (int k = 1; k <= c; k++)
                {
                    scanf("%d", &map[i][j][k]);
                }
            }
        }
        Point start = {1, 1, 1, 0}, end = {a, b, c, -1};
        if (map[a][b][c] == 1) // 人一开始的位置是墙不应该输出-1吗……
        {
            printf("-1\n");
        }
        else if (start == end)
        {
            printf("0\n");
        }
        else if (a + b + c - 3 > maxtime) // minimum time > T
        {
            printf("-1\n");
        }
        else
        {
            printf("%d\n", bfs(start, end, maxtime));
        }
    }
    return 0;
}
