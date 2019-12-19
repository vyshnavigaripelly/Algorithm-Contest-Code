#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>
#include <algorithm>

#define maxn 100007
#define maxp 1007

using namespace std;

struct
{
    int w;
    int to;
    int next;
} edge[maxn];

int head[maxp], cnt, s, t;
bool inq[maxp];

struct Pre
{
    int v;
    int edge;
} pre[maxp];

inline void add(int u, int v, int w)
{
    edge[cnt].to = v;
    edge[cnt].w = w;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

inline bool bfs()
{
    queue<int> q;
    memset(inq, 0, sizeof(inq));
    memset(pre, -1, sizeof(pre));
    inq[s] = 1;
    q.push(s);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (!inq[v] && edge[i].w)
            {
                pre[v].v = now;
                pre[v].edge = i;
                if (v == t)
                    return 1;
                inq[v] = 1;
                q.push(v);
            }
        }
    }
    return 0;
}

int EK()
{
    int ans = 0;
    while (bfs())
    {
        int mi = 0x3f3f3f3f;
        for (int i = t; i != s; i = pre[i].v)
        {
            mi = min(mi, edge[pre[i].edge].w);
        }
        for (int i = t; i != s; i = pre[i].v)
        {
            edge[pre[i].edge].w -= mi;
            edge[pre[i].edge ^ 1].w += mi;
        }
        ans += mi;
    }
    return ans;
}

int main()
{
    memset(head, -1, sizeof(head));
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    s = 0;
    t = n + m + 2;
    add(s, 1, k);
    add(1, s, 0);
    for (int i = 2; i <= n + 1; i++)
    {
        add(s, i, 1);
        add(i, s, 0);
        add(1, i, 1);
        add(i, 1, 0);
    }
    for (int i = n + 2; i <= n + m + 1; i++)
    {
        add(i, t, 1);
        add(t, i, 0);
    }
    for (int i = 2; i <= n + 1; i++)
    {
        int num, v;
        scanf("%d", &num);
        while (num--)
        {
            scanf("%d", &v);
            add(i, n + 1 + v, 1);
            add(n + 1 + v, i, 0);
        }
    }
    printf("%d\n", EK());
    return 0;
}
