#include <iostream>
#include <cstring>
#include <queue>
#include <functional>

using namespace std;

const int N = 1e3 + 7;

struct
{
    int next;
    int to;
    long long w;
} edge[N];

int cnt, n, m;
int head[N];

void add(int u, int v, long long w)
{
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}

queue<int> q;

long long spfa(int s, int t)
{
    long long d[307];
    int vis[307] = {0};
    memset(d, 0x3f, sizeof(d));
    vis[s] = 1;
    d[s] = 0;
    q.push(s);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        vis[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to, w = edge[i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (vis[v])
                    continue;
                vis[v] = 1;
                q.push(v);
            }
        }
    }
    return -d[t];
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int u, v;
            long long w;
            scanf("%d%d%lld", &u, &v, &w);
            add(u, v, w);
        }
        for (int i = 0; i < 6; i++)
        {
            int s, t;
            scanf("%d%d", &s, &t);
            long long minw = spfa(t, s);
            add(s, t, minw);
            printf("%lld\n", minw);
        }
    }
    return 0;
}