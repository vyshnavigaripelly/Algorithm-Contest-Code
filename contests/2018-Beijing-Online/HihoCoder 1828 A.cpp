#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 107;
const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

struct node
{
    int x, y, step;
    int o;
    node(int x, int y, int step, int o) : x(x), y(y), step(step), o(o) {}
    node() {}
};

int n, m, stx, sty, edx, edy;
char mp[N][N];
int vis[7][N][N];
queue<node> q;

void bfs()
{
    while (q.size())
    {
        q.pop();
    }
    vis[0][stx][sty] = 1;
    q.push(node(stx, sty, 1, 0));
    while (q.size())
    {
        node now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if (dx >= 0 && dx < n && dy >= 0 && dy < m)
            {
                if (mp[dx][dy] == '.' || mp[dx][dy] == 'S' || mp[dx][dy] == 'T')
                {
                    if (vis[now.o][dx][dy] > now.step + 1)
                    {
                        vis[now.o][dx][dy] = now.step + 1;
                        q.push(node(dx, dy, now.step + 1, now.o));
                    }
                }
                else if (mp[dx][dy] == 'B')
                {
                    int nxt = min(5, now.o + 1);
                    if (vis[nxt][dx][dy] > now.step + 1)
                    {
                        vis[nxt][dx][dy] = now.step + 1;
                        q.push(node(dx, dy, now.step + 1, nxt));
                    }
                }
                else if (mp[dx][dy] == 'P')
                {
                    if (vis[now.o][dx][dy] > now.step)
                    {
                        vis[now.o][dx][dy] = now.step;
                        q.push(node(dx, dy, now.step, now.o));
                    }
                }
                else
                {
                    if (now.o > 0)
                    {
                        if (vis[now.o - 1][dx][dy] > now.step + 2)
                        {
                            vis[now.o - 1][dx][dy] = now.step + 2;
                            q.push(node(dx, dy, now.step + 2, now.o - 1));
                        }
                    }
                }
            }
        }
    }
}

int main()
{
    while (scanf("%d %d", &n, &m) && (n && m))
    {
        memset(vis, 0x3f, sizeof(vis));
        for (int i = 0; i < n; i++)
        {
            scanf("%s", mp[i]);
            for (int j = 0; j < m; j++)
            {
                if (mp[i][j] == 'S')
                {
                    stx = i, sty = j;
                }
                else if (mp[i][j] == 'T')
                {
                    edx = i, edy = j;
                }
            }
        }
        bfs();
        int ans = 0x3f3f3f3f;
        for (int i = 0; i < 6; i++)
        {
            ans = min(vis[i][edx][edy], ans);
        }
        printf("%d\n", ans == 0x3f3f3f3f ? -1 : ans - 1);
    }
    return 0;
}