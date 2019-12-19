#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e4 + 7;
const long long INF = 0x3f3f3f3f3f3f3f3f;

struct node
{
    int to;
    int next;
    long long w;
} edge1[N << 1], edge2[N << 1], edge3[N << 1];

int n, m, s, t, head1[N], head2[N], head3[N], vis[N], cnt1, cnt2, cnt3;
long long d1[N], d2[N], d3[N];
deque<int> q;

void add1(int u, int v, long long w)
{
    edge1[cnt1].next = head1[u];
    edge1[cnt1].to = v;
    edge1[cnt1].w = w;
    head1[u] = cnt1++;
}

void add2(int u, int v, long long w)
{
    edge2[cnt2].next = head2[u];
    edge2[cnt2].to = v;
    edge2[cnt2].w = w;
    head2[u] = cnt2++;
}

void add3(int u, int v, long long w)
{
    edge3[cnt3].next = head3[u];
    edge3[cnt3].to = v;
    edge3[cnt3].w = w;
    head3[u] = cnt3++;
}

void spfa1()
{
    while (q.size())
        q.pop_back();
    memset(d1, 0x3f, sizeof(d1));
    memset(vis, 0, sizeof(vis));
    q.push_back(1);
    vis[1] = 1;
    d1[1] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop_front();
        vis[u] = 0;
        for (int i = head1[u]; ~i; i = edge1[i].next)
        {
            int v = edge1[i].to;
            long long w = edge1[i].w;
            if (d1[v] > d1[u] + w)
            {
                d1[v] = d1[u] + w;
                if (vis[v])
                    continue;
                vis[v] = 1;
                if (q.size() == 0)
                {
                    q.push_back(v);
                }
                else if (d1[q.front()] >= d1[v])
                {
                    q.push_front(v);
                }
                else
                {
                    q.push_back(v);
                }
            }
        }
    }
}

void spfa2()
{
    while (q.size())
        q.pop_back();
    memset(d2, 0x3f, sizeof(d2));
    memset(vis, 0, sizeof(vis));
    q.push_back(n);
    vis[n] = 1;
    d2[n] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop_front();
        vis[u] = 0;
        for (int i = head2[u]; ~i; i = edge2[i].next)
        {
            int v = edge2[i].to;
            long long w = edge2[i].w;
            if (d2[v] > d2[u] + w)
            {
                d2[v] = d2[u] + w;
                if (vis[v])
                    continue;
                vis[v] = 1;
                if (q.size() == 0)
                {
                    q.push_back(v);
                }
                else if (d2[q.front()] >= d2[v])
                {
                    q.push_front(v);
                }
                else
                {
                    q.push_back(v);
                }
            }
        }
    }
}

int bfs()
{
    while (q.size())
        q.pop_back();
    memset(d3, 0, sizeof(d3));
    q.push_back(s);
    d3[s] = 1;
    while (q.size())
    {
        int x = q.front();
        q.pop_front();
        for (int i = head3[x]; ~i; i = edge3[i].next)
        {
            int v = edge3[i].to;
            if (edge3[i].w && !d3[v])
            {
                q.push_back(v);
                d3[v] = d3[x] + 1;
                if (v == t)
                    return 1;
            }
        }
    }
    return 0;
}

long long dinic(int x, long long flow)
{
    if (x == t)
        return flow;
    long long rest = flow, k;
    for (int i = head3[x]; ~i && rest; i = edge3[i].next)
    {
        int v = edge3[i].to;
        long long w = edge3[i].w;
        if (w && d3[v] == d3[x] + 1)
        {
            k = dinic(v, min(rest, (long long)w));
            if (!k)
            {
                d3[v] = 0;
            }
            edge3[i].w -= k;
            edge3[i ^ 1].w += k;
            rest -= k;
        }
    }
    return flow - rest;
}

void init()
{
    memset(head1, -1, sizeof(head1));
    memset(head2, -1, sizeof(head2));
    memset(head3, -1, sizeof(head3));
    cnt1 = 0, cnt2 = 0, cnt3 = 0;
    s = 1, t = n;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        init();
        int u, v, w;
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &u, &v, &w);
            add1(u, v, w);
            add2(v, u, w);
        }
        spfa1();
        if (d1[n] == INF)
        {
            printf("0\n");
            continue;
        }
        spfa2();
        for (int i = 1; i <= n; i++)
        {
            for (int j = head1[i]; ~j; j = edge1[j].next)
            {
                int v = edge1[j].to;
                if (d1[i] + d2[v] + edge1[j].w == d1[n])
                {
                    add3(i, v, edge1[j].w);
                    add3(v, i, 0);
                }
            }
        }
        long long ans = 0, flow = 0;
        while (bfs())
        {
            while (flow = dinic(s, INF))
            {
                ans += flow;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}