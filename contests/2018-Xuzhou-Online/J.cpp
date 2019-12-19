#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

const int N = 3e5 + 7;
const int M = 2e6 + 7;

struct e
{
    int u, v;
    long long w;
    bool operator<(const e &a) const
    {
        return a.w < w;
    }
} ed[M];

struct node
{
    long long w;
    int to;
    int next;
} edge[M];

int t, n, m, tot, cnt;
int d[N], f[N][20], bcj[N], head[N];
long long dist[N];
queue<int> q;

int Find(int x)
{
    return bcj[x] < 0 ? x : bcj[x] = Find(bcj[x]);
}

void add(int u, int v, long long w)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    head[u] = cnt++;
}

void kruskal()
{
    int now = 0;
    for (int i = 0; i < tot; i++)
    {
        int u = Find(ed[i].u);
        int v = Find(ed[i].v);
        if (u == v)
            continue;
        bcj[u] = v;
        add(ed[i].u, ed[i].v, ed[i].w);
        add(ed[i].v, ed[i].u, ed[i].w);
        if (++now == (n * m) - 1)
            break;
    }
}

void bfs()
{
    q.push(1);
    d[1] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop();
        for (int i = head[x]; ~i; i = edge[i].next)
        {
            int y = edge[i].to;
            if (d[y])
                continue;
            d[y] = d[x] + 1;
            dist[y] = dist[x] + 1;
            f[y][0] = x;
            for (int j = 1; j <= t; j++)
            {
                f[y][j] = f[f[y][j - 1]][j - 1];
            }
            q.push(y);
        }
    }
}

int lca(int x, int y)
{
    if (d[x] > d[y])
        swap(x, y);
    for (int i = t; i >= 0; i--)
    {
        if (d[f[y][i]] >= d[x])
        {
            y = f[y][i];
        }
    }
    if (x == y)
        return x;
    for (int i = t; i >= 0; i--)
    {
        if (f[x][i] != f[y][i])
            x = f[x][i], y = f[y][i];
    }
    return f[x][0];
}

int main()
{
    memset(bcj, -1, sizeof(bcj));
    memset(head, -1, sizeof(head));
    scanf("%d %d", &n, &m);
    t = (int)(log(n * m) / log(2)) + 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            char ch1[2], ch2[2];
            long long w1, w2;
            scanf("%s %lld %s %lld", ch1, &w1, ch2, &w2);
            if (ch1[0] == 'D')
            {
                ed[tot].u = i * n + j;
                ed[tot].v = i * n + j + n;
                ed[tot].w = w1;
                tot++;
            }
            if (ch1[0] == 'R')
            {
                ed[tot].u = i * n + j;
                ed[tot].v = i * n + j + 1;
                ed[tot].w = w1;
                tot++;
            }
            if (ch2[0] == 'D')
            {
                ed[tot].u = i * n + j;
                ed[tot].v = i * n + j + n;
                ed[tot].w = w2;
                tot++;
            }
            if (ch2[0] == 'R')
            {
                ed[tot].u = i * n + j;
                ed[tot].v = i * n + j + 1;
                ed[tot].w = w2;
                tot++;
            }
        }
    }
    sort(ed, ed + tot);
    kruskal();
    bfs();
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int u = (x1 - 1) * n + y1, v = (x2 - 1) * n + y2;
        printf("%lld\n", dist[u] + dist[v] - 2 * dist[lca(u, v)]);
    }
    return 0;
}