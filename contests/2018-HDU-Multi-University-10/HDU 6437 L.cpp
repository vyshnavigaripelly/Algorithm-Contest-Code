#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>
#include <vector>

#define maxn 3000007
#define maxp 10007

using namespace std;

struct
{
    int w; //容量
    int to;
    int cost; //费用
    int next;
} edge[maxn];

int head[maxp], d[maxp], st[maxp], ed[maxp], happy[maxp], type[maxp], cnt, s, t, n, m, K, W;
bool inq[maxp];

struct Pre
{
    int v;
    int edge;
} pre[maxp];

inline void add(int u, int v, int w, int cost)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].cost = cost;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

inline bool spfa()
{
    queue<int> q;
    memset(inq, 0, (t + 1) * sizeof(bool));
    memset(d, 0x3f, (t + 1) * sizeof(int));
    memset(pre, 0, (t + 1) * sizeof(int));
    inq[s] = 1;
    q.push(s);
    d[s] = 0;
    while (!q.empty())
    {
        int now = q.front();
        inq[now] = 0;
        q.pop();
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            int w = edge[i].cost;
            if (edge[i].w > 0 && d[v] > d[now] + w)
            {
                d[v] = d[now] + w;
                pre[v].v = now;
                pre[v].edge = i;
                if (inq[v] == 0)
                {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return d[t] != 0x3f3f3f3f;
}

int EK()
{
    int maxflow = 0;
    int cost = 0;
    int mi;
    while (spfa())
    {
        mi = 0x3f3f3f3f;
        for (int i = t; i != s; i = pre[i].v)
            mi = min(mi, edge[pre[i].edge].w);
        for (int i = t; i != s; i = pre[i].v)
        {
            edge[pre[i].edge].w -= mi;
            edge[pre[i].edge ^ 1].w += mi;
        }
        maxflow += mi;
        cost += mi * d[t];
    }
    return -cost;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        //1源点 1-K人 (K+1)~(K+2m)为电影(拆点) 2m+K+1汇点
        //源点到人   人到所有电影， 电影之间按时间连边， 所有电影到汇点。
        scanf("%d%d%d%d", &n, &m, &K, &W);
        memset(head, -1, sizeof(head));
        t = 2 * m + K + 1, cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d%d", &st[i], &ed[i], &happy[i], &type[i]);
            add(i + K + m, t, 1, 0);
            add(t, i + K + m, 0, 0);
            add(i + K, i + K + m, 1, 0);
            add(i + K + m, i + K, 0, 0);
        }
        for (int i = 1; i <= K; i++)
        {
            add(s, i, 1, 0);
            add(i, s, 0, 0);
            for (int j = 1; j <= m; j++)
            {
                add(i, j + K, 1, -happy[j]);
                add(j + K, i, 0, happy[j]);
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (i == j)
                    continue;
                if (ed[i] <= st[j])
                {
                    int cost = happy[j];
                    if (type[i] == type[j])
                        cost -= W;
                    add(i + K + m, j + K, 1, -cost);
                    add(j + K, i + K + m, 0, cost);
                }
            }
        }
        printf("%d\n", EK());
    }
    return 0;
}