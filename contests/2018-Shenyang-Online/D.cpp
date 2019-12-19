#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

#define MAXN 1005
#define MAXM 10005
#define INF 1e9

using namespace std;

struct node
{
    int next;
    int to;
    int w;
} edge[MAXM], revedge[MAXM];

struct A
{
    int f, g, v;
    bool operator<(const A a) const
    {
        if (a.f == f)
            return a.g < g;
        return a.f < f;
    }
};

int cnt, vis[MAXN], d[MAXN], q[MAXM * 5];
int head[MAXN], revhead[MAXN];
int s, e, k, t, n, m;

void init()
{
    cnt = 0;
    memset(head, -1, sizeof(head));
    memset(revhead, -1, sizeof(revhead));
    for (int i = 1; i <= n; i++)
        d[i] = INF;
}

void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt;

    revedge[cnt].w = w;
    revedge[cnt].to = u;
    revedge[cnt].next = revhead[v];
    revhead[v] = cnt++;
}

void spfa(int st)
{
    memset(vis, 0, sizeof(vis));
    vis[st] = 0;
    q[0] = st;
    d[st] = 0;

    int now = 0, limit = 1;
    while (now < limit)
    {
        int u = q[now++];
        vis[u] = 0;
        for (int i = revhead[u]; ~i; i = revedge[i].next)
        {
            int v = revedge[i].to;
            int w = revedge[i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!vis[v])
                {
                    q[limit++] = v;
                    vis[v] = 1;
                }
            }
        }
    }
}

int Astar(int st, int ed)
{
    int counter = 0;
    priority_queue<A> Q;

    if (d[st] == INF)
        return -1;

    A t, tt;
    t.v = st, t.g = 0, t.f = t.g + d[st];
    Q.push(t);
    while (!Q.empty())
    {
        tt = Q.top();
        Q.pop();
        if (tt.v == ed)
        {
            counter++;
            if (counter == k)
                return tt.g;
        }
        for (int i = head[tt.v]; ~i; i = edge[i].next)
        {
            t.v = edge[i].to;
            t.g = tt.g + edge[i].w;
            t.f = t.g + d[t.v];
            Q.push(t);
        }
    }
    return -1;
}

int main()
{
    int u, v, w;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        init();

        scanf("%d%d%d%d", &s, &e, &k, &t);

        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
        }

        spfa(e);

        int ans = Astar(s, e);
        if (ans > t || ans == -1)
            cout << "Whitesnake!" << endl;
        else
            cout << "yareyaredawa" << endl;
    }
    return 0;
}
