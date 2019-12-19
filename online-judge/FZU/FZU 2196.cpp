#include <iostream>
#include <queue>
#include <cstring>
#include <string>
using namespace std;

const int MAXN = 1005;

struct Point
{
    int x, y, step;
    Point() {}
    Point(int x, int y, int step) : x(x), y(y), step(step) {}
};

char map[MAXN][MAXN];
int vis[MAXN][MAXN], lavatime[MAXN][MAXN];

int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
int n, m;

queue<Point> qLava, qMap;

int check(int x, int y)
{
    if (x >= 0 && x < n && y >= 0 && y < m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void BfsLava()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (map[i][j] == '!')
            {
                lavatime[i][j] = 0;
                qLava.push(Point(i, j, 0));
            }
        }
    }
    while (!qLava.empty())
    {
        Point cur = qLava.front();
        qLava.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next(cur.x + dir[i][0], cur.y + dir[i][1], cur.step + 1);
            if (check(next.x, next.y) && next.step < lavatime[next.x][next.y])
            {
                lavatime[next.x][next.y] = next.step;
                qLava.push(next);
            }
        }
    }
    return;
}

string BfsMap(Point start, Point end)
{
    vis[start.x][start.y] = 1;
    qMap.push(start);
    while (!qMap.empty())
    {
        Point cur = qMap.front();
        qMap.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next(cur.x + dir[i][0], cur.y + dir[i][1], cur.step + 1);
            if (check(next.x, next.y) && !vis[next.x][next.y] && next.step < lavatime[next.x][next.y])
            {
                vis[next.x][next.y] = 1;
                qMap.push(next);
            }
            if (next.x == end.x && next.y == end.y && next.step <= lavatime[next.x][next.y])
            {
                return "Yes";
            }
        }
    }
    return "No";
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(map, 0, sizeof(map));
        memset(vis, 0, sizeof(vis));
        memset(lavatime, 0x3f, sizeof(lavatime));
        while (!qLava.empty())
        {
            qLava.pop();
        }
        while (!qMap.empty())
        {
            qMap.pop();
        }

        scanf("%d %d", &n, &m);
        Point start, end;
        for (int i = 0; i < n; i++)
        {
            scanf("%s", map[i]);
            for (int j = 0; j < m; j++)
            {
                if (map[i][j] == 'S')
                {
                    start = Point(i, j, 0);
                }
                if (map[i][j] == 'E')
                {
                    end = Point(i, j, -1);
                }
                if (map[i][j] == '#')
                {
                    lavatime[i][j] = 0;
                }
            }
        }
        BfsLava();
        cout << BfsMap(start, end) << endl;
    }
    return 0;
}
