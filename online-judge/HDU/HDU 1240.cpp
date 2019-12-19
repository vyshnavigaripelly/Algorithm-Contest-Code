#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;

struct Point
{
    int x, y, z;
};

int vis[15][15][15], step[15][15][15];
char map[15][15][15];
queue<Point> q;

int bfs(int n, Point start, Point end)
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
            Point next = {cur.x + dir[i][0], cur.y + dir[i][1], cur.z + dir[i][2]};
            if (map[next.x][next.y][next.z] == 'X')
            {
                continue;
            }
            if (!vis[next.x][next.y][next.z])
            {
                step[next.x][next.y][next.z] = step[cur.x][cur.y][cur.z] + 1;
                vis[next.x][next.y][next.z] = 1;
                q.push(next);
            }
            if (map[next.x][next.y][next.z] == 'E')
            {
                return step[next.x][next.y][next.z];
            }
        }
    }
    return -1;
}

int main()
{
    string s;
    int n;
    while (cin >> s >> n)
    {
        memset(map, 'X', sizeof(map));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                for (int k = 1; k <= n; k++)
                {
                    cin >> map[i][j][k];
                }
            }
        }
        Point start, end;
        cin >> start.x >> start.y >> start.z;
        cin >> end.x >> end.y >> end.z;
        start.x++, start.y++, start.z++; // set origin to 1,1,1
        end.x++, end.y++, end.z++;
        map[end.x][end.y][end.z] = 'E';
        cin >> s; // input END
        if (map[start.x][start.y][start.z] == 'E') // start point == end point
        {
            cout << n << ' ' << 0 << endl;
        }
        else
        {
            int ans = bfs(n, start, end);
            if (ans == -1)
            {
                cout << "NO ROUTE" << endl;
            }
            else
            {
                cout << n << ' ' << ans << endl;
            }
        }
    }
    return 0;
}
