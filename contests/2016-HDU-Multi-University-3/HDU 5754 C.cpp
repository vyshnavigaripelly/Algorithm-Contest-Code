#include <iostream>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int N = 1e6 + 7;
const int dir[3][2] = {1, 0, 0, 1, 1, 1};
const double r = (sqrt(5.0) + 1) / 2;

struct
{
    int to;
    int next;
} edge[N << 2], reverEdge[N << 2];

int mp[1007][1007], v[1007][1007], cnt, tot;
int SG[N], vis[N], head[N], reverHead[N], out[N];
queue<pair<int, int>> q;
queue<int> Q;

void add(int u, int v)
{
    cnt++;
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt;

    reverEdge[cnt].next = reverHead[v];
    reverEdge[cnt].to = u;
    reverHead[v] = cnt;
}

void pre()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 1; j <= 1000; j++)
        {
            mp[i][j] = ++tot;
        }
    }
    q.push(make_pair(1, 1));
    v[1][1] = 1;
    while (q.size())
    {
        pair<int, int> now = q.front();
        q.pop();
        int u = mp[now.first][now.second];
        for (int i = 0; i < 3; i++)
        {
            int dx = now.first + dir[i][0], dy = now.second + dir[i][1];
            if (dx <= 1000 && dy <= 1000)
            {
                out[u]++;
                add(u, mp[dx][dy]);
                if (!v[dx][dy])
                {
                    v[dx][dy] = 1;
                    q.push(make_pair(dx, dy));
                }
            }
        }
    }
}

void sg()
{
    pre();
    for (int i = 1; i <= tot; i++)
    {
        if (!out[i])
        {
            Q.push(i);
        }
    }
    while (Q.size())
    {
        int u = Q.front(), j;
        Q.pop();
        int Max = 0;
        for (j = head[u]; j; j = edge[j].next)
        {
            int v = edge[j].to;
            vis[SG[v]] = 1;
            Max = (Max, SG[v]);
        }
        for (j = 0; j <= Max + 1; j++)
        {
            if (!vis[j])
                break;
        }
        SG[u] = j;
        for (j = 0; j <= Max; j++)
            vis[j] = 0;
        for (j = reverHead[u]; j; j = reverEdge[j].next)
        {
            int v = reverEdge[j].to;
            if (--out[v] == 0)
            {
                Q.push(v);
            }
        }
    }
}

int main()
{
    sg();
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int type, n, m;
        scanf("%d%d%d", &type, &n, &m);
        if (n > m)
        {
            swap(n, m);
        }
        n--, m--;
        if (type == 1)
        {
            if (SG[mp[1000 - n][1000 - m]])
            {
                puts("B");
            }
            else
            {
                puts("G");
            }
        }
        if (type == 2)
        {
            if (n ^ m)
            {
                puts("B");
            }
            else
            {
                puts("G");
            }
        }
        if (type == 3)
        {
            if (n == m && n % 3 == 0)
            {
                puts("G");
            }
            else if ((m - n) == 1 && (n - 1) % 3 == 0)
            {
                puts("B");
            }
            else
            {
                puts("D");
            }
        }
        if (type == 4)
        {
            double c = m - n;
            double tmp = (int)(r * c);
            if (tmp == n)
            {
                puts("G");
            }
            else
            {
                puts("B");
            }
        }
    }
    return 0;
}