#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>
#include <cstdio>

const int N = 100007;
const long long INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

int n, m, cnt;
int head[N], inq[N];
long long dt[N], dc[N];

struct node
{
    int to;
    int next;
    int cost;
    int time;
} edge[N * 2];

void spfa()
{
    queue<int> Q;
    inq[0] = 1;
    dt[0] = 0;
    dc[0] = 0;
    Q.push(0);
    while (Q.size())
    {
        int now = Q.front();
        Q.pop();
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int v = edge[i].to, t = edge[i].time, c = edge[i].cost;
            if (dt[v] > dt[now] + t || (dt[v] == dt[now] + t && dc[v] > c))
            {
                dt[v] = dt[now] + t;
                dc[v] = c;
                if (inq[v])
                    continue;
                Q.push(v);
                inq[v] = 1;
            }
        }
        inq[now] = 0;
    }
}

void add(int u, int v, int time, int cost)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    edge[cnt].cost = cost;
    edge[cnt].time = time;
    head[u] = cnt++;
}

void init()
{
    for (int i = 0; i < n; i++)
    {
        inq[i] = 0;
        dt[i] = INF;
        dc[i] = INF;
        head[i] = -1;
    }
    cnt = 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y, d, c;
        long long anst = 0, ansc = 0;
        scanf("%d%d", &n, &m);
        init();
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d%d", &x, &y, &d, &c);
            add(x, y, d, c);
            add(y, x, d, c);
        }
        spfa();
        for (int i = 1; i < n; i++)
        {
            anst += dt[i];
            ansc += dc[i];
        }
        printf("%lld %lld\n", anst, ansc);
    }
    return 0;
}