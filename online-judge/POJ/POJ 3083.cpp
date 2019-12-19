#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

struct Point
{
    int x, y, step;
};

const int N = 45;

char map[N][N];
int vis[N][N];

int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
int w, h, done, ansLeft, ansRight, sx, sy, ex, ey;

queue<Point> q;

bool checkDfs(int x, int y)
{
    return (x >= 0 && x < h && y >= 0 && y < w && !done && map[x][y] != '#');
}

bool checkBfs(int x, int y)
{
    return (x >= 0 && x < h && y >= 0 && y < w && map[x][y] != '#' && !vis[x][y]);
}

//             [0]
//            x-1,y
// [3] x,y-1   x,y   x,y+1 [1]
//            x+1,y
//             [2]

void dfsLeft(int x, int y, int step, int face)
{
    if (done)
    {
        return;
    }
    if (x == ex && y == ey)
    {
        done = 1;
        ansLeft = step;
        return;
    }
    for (int i = -1; i <= 2; i++)
    {
        int nf = (face + i + 4) % 4, nx = x + dir[nf][0], ny = y + dir[nf][1];
        if (checkDfs(nx, ny))
        {
            dfsLeft(nx, ny, step + 1, nf);
        }
    }
    return;
}

void dfsRight(int x, int y, int step, int face)
{
    if (done)
    {
        return;
    }
    if (x == ex && y == ey)
    {
        done = 1;
        ansRight = step;
        return;
    }
    for (int i = 1; i >= -2; i--)
    {
        int nf = (face + i + 4) % 4, nx = x + dir[nf][0], ny = y + dir[nf][1];
        if (checkDfs(nx, ny))
        {
            dfsRight(nx, ny, step + 1, nf);
        }
    }
    return;
}

int bfs()
{
    Point start = {sx, sy, 1};
    vis[sx][sy] = 1;
    q.push(start);
    while (!q.empty())
    {
        Point cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], cur.step + 1};
            if (checkBfs(next.x, next.y))
            {
                vis[next.x][next.y] = 1;
                q.push(next);
            }
            if (next.x == ex && next.y == ey)
            {
                return next.step;
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
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        ansLeft = ansRight = done = 0;
        cin >> w >> h;
        for (int i = 0; i < h; i++)
        {
            cin >> map[i];
            for (int j = 0; j < w; j++)
            {
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
        dfsLeft(sx, sy, 1, 0);
        done = 0;
        dfsRight(sx, sy, 1, 0);
        int shortest = bfs();
        cout << ansLeft << ' ' << ansRight << ' ' << shortest << endl;
    }
    return 0;
}
