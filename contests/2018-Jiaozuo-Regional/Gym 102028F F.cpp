#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

const int dir[6][2] = {-1, -3, -2, 0, -1, 3, 1, -3, 2, 0, 1, 3};

struct node
{
    int x, y, value;
    node(int x, int y, int value) : x(x), y(y), value(value) {}
    node() {}
};

char mp[4007][6007];
int d[4007][6007], inq[4007][6007], r, c;
node s, t;

void init()
{
    for (int i = 0; i < 4 * r + 3; i++)
    {
        for (int j = 0; j < 6 * c + 3; j++)
        {
            d[i][j] = 0x3f3f3f3f;
            if (mp[i][j] == 'S')
            {
                s.x = i;
                s.y = j;
                s.value = 0;
            }
            else if (mp[i][j] == 'T')
            {
                t.x = i;
                t.y = j;
            }
        }
    }
}

void bfs()
{
    queue<node> Q;
    Q.push(s);
    inq[s.x][s.y] = 1;
    d[s.x][s.y] = 0;
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        inq[now.x][now.y] = 0;
        if (now.x == t.x && now.y == t.y)
            continue;
        for (int i = 0; i < 6; i++)
        {
            int dx = now.x + dir[i][0];
            int dy = now.y + dir[i][1];
            if (dx > -1 && dx < 4 * r + 2 && dy > -1 && dy < 6 * c + 3 && mp[dx][dy] == ' ')
            {
                if (d[dx + dir[i][0]][dy + dir[i][1]] > now.value + 1)
                {
                    d[dx + dir[i][0]][dy + dir[i][1]] = now.value + 1;
                    if (inq[dx + dir[i][0]][dy + dir[i][1]])
                        continue;
                    inq[dx + dir[i][0]][dy + dir[i][1]] = 1;
                    Q.push(node(dx + dir[i][0], dy + dir[i][1], now.value + 1));
                }
            }
        }
    }
}

int main()
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d", &r, &c);
        getchar();
        for (int i = 0; i < 4 * r + 3; i++)
        {
            gets(mp[i]);
        }
        init();
        bfs();
        if (d[t.x][t.y] == 0x3f3f3f3f)
            printf("-1\n");
        else
            printf("%d\n", 1 + d[t.x][t.y]);
    }
    return 0;
}