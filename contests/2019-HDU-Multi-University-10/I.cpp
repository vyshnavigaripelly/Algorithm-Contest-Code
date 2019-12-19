#include <bits/stdc++.h>

using namespace std;

const int N = 2007;

const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int n, m, q, u, v;
int value[4] = {10, 10, 1, 1};
int block[N][N], knocked[N][N];

int check(int x, int y)
{
    if (x >= 1 && x <= n && y >= 1 && y <= m)
    {
        return 1;
    }
    return 0;
}

int bfs()
{
    queue<pair<int, int>> q;
    int ans = 1;
    knocked[u][v] = 1;
    q.push(make_pair(u, v));
    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dx = now.first + dir[i][0];
            int dy = now.second + dir[i][1];
            if (!knocked[dx][dy] && check(dx, dy))
            {
                block[dx][dy] -= value[i];
                if (block[dx][dy] < 20 && (block[dx][dy] % 10 < 2))
                {
                    knocked[dx][dy] = 1;
                    q.push(make_pair(dx, dy));
                    ans++;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d%d", &n, &m, &q);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                block[i][j] = 22;
            }
        }
        memset(knocked, 0, sizeof(knocked));
        while (q--)
        {
            scanf("%d%d", &u, &v);
            if (knocked[u][v])
            {
                printf("0\n");
                continue;
            }
            printf("%d\n", bfs());
        }
    }
    return 0;
}