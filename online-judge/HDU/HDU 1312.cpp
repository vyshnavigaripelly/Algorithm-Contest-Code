#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

struct Node
{
    int x, y;
};

int vis[25][25];
char map[25][25];
queue<Node> q;

int bfs(int w, int h, int stx, int sty)
{
    int cnt = 1, dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    Node cur = {stx, sty};
    vis[stx][sty] = 1;
    q.push(cur);
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            Node next = {cur.x + dir[i][0], cur.y + dir[i][1]};
            if (map[next.x][next.y] == '#')
            {
                continue;
            }
            if (!vis[next.x][next.y])
            {
                cnt++;
                vis[next.x][next.y] = 1;
                q.push(next);
            }
        }
    }
    return cnt;
}

int main()
{
    int w, h;
    while (cin >> w >> h && (w || h))
    {
        memset(map, '#', sizeof(map));
        memset(vis, 0, sizeof(vis));
        while (!q.empty())
        {
            q.pop();
        }
        int stx, sty;
        for (int i = 1; i <= h; i++)
        {
            for (int j = 1; j <= w; j++)
            {
                cin >> map[i][j];
                if (map[i][j] == '@')
                {
                    stx = i;
                    sty = j;
                }
            }
        }
        cout << bfs(w, h, stx, sty) << endl;
    }
    return 0;
}
