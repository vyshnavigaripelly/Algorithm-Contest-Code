#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int INF = 0x3f3f3f3f;
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct node
{
    int x, y, value;
    node(int x, int y, int value) : x(x), y(y), value(value) {}
    node() {}
};

char mp[107][107];
int d[1 << 4][107][107], cnt, k, n, m;
node point[5];

void bfs()
{
    int tar = (1 << k) - 1, ans = INF;
    memset(d, 0x3f, sizeof(d));
    queue<node> Q;
    Q.push(point[0]);
    d[0][point[0].x][point[0].y] = 0;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        if (now.value == tar)
        {
            ans = d[tar][now.x][now.y];
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if (dx > 0 && dx <= n && dy > 0 && dy <= m && mp[dx][dy] != '#' && mp[dx][dy] != '@')
            {
                int next;
                if (mp[dx][dy] < 5)
                {
                    next = now.value | (1 << mp[dx][dy]);
                    if (d[next][dx][dy] > d[now.value][now.x][now.y] + 1)
                    {
                        d[next][dx][dy] = d[now.value][now.x][now.y] + 1;
                        Q.push(node(dx, dy, next));
                    }
                }
                else if (mp[dx][dy] == '.')
                {
                    if (d[now.value][dx][dy] > d[now.value][now.x][now.y] + 1)
                    {
                        d[now.value][dx][dy] = d[now.value][now.x][now.y] + 1;
                        Q.push(node(dx, dy, now.value));
                    }
                }
            }
        }
    }
    printf("%d\n", (ans == INF ? -1 : ans));
}

int main()
{
    while (scanf("%d %d", &n, &m) && (n || m))
    {
        for (int i = 1; i <= n; i++)
        {
            getchar();
            for (int j = 1; j <= m; j++)
            {
                scanf("%c", &mp[i][j]);
                if (mp[i][j] == '@')
                {
                    point[0].x = i, point[0].y = j, point[0].value = 0;
                }
            }
        }
        scanf("%d", &k);
        for (int i = 1; i <= k; i++)
        {
            scanf("%d %d", &point[i].x, &point[i].y);
            mp[point[i].x][point[i].y] = i - 1;
            point[i].value = 0;
        }
        bfs();
    }
    return 0;
}