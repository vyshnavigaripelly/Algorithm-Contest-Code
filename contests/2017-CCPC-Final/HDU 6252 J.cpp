#include <bits/stdc++.h>

using namespace std;

const int N = 2E3 + 7;
const int M = N * N;

struct node
{
    int next, to;
    long long w;
    node(int next, int to, long long w) : next(next), to(to), w(w) {}
    node() {}
} edge[M];

int n, m, x, cnt;
int head[N], vis[N], inq[N];
long long d[N];
queue<int> q;

void add(int u, int v, int w)
{
    edge[cnt] = node(head[u], v, w);
    head[u] = cnt++;
}

int spfa()
{
    while (q.size())
        q.pop();
    memset(d, 0x3f, sizeof(d));
    memset(inq, 0, sizeof(inq));
    memset(vis, 0, sizeof(vis));
    q.push(0);
    inq[0] = 1;
    d[0] = 0;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        if (++vis[u] > n)
        {
            return 0;
        }
        inq[u] = 0;
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to, w = edge[i].w;
            if (d[v] > d[u] + w)
            {
                d[v] = d[u] + w;
                if (!inq[v])
                {
                    q.push(v);
                    inq[v] = 1;
                }
            }
        }
    }
    return 1;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(head, -1, sizeof(head));
        cnt = 0;
        scanf("%d%d%d", &n, &m, &x);
        for (int i = 1; i < n; i++)
        {
            add(i + 1, i, -1);
            add(0, i, 0);
        }
        add(0, n, 0);
        for (int i = 0; i < m; i++)
        {
            int a, b, c, d;
            scanf("%d%d%d%d", &a, &b, &c, &d);
            if (a == b)
            {
                if (c == d)
                {
                    add(a, c, x);
                    add(c, a, -x);
                }
                else
                {
                    add(d, a, -(x + 1));
                    add(a, c, x - 1);
                }
            }
            else
            {
                if (c == d)
                {
                    add(b, c, x - 1);
                    add(c, a, -(x + 1));
                }
                else
                {
                    if (c > b)
                    {
                        add(b, c, x - 1);
                    }
                    add(d, a, -(x + 1));
                }
            }
        }
        int flag = spfa();
        printf("Case #%d: ", cas);
        if (flag)
        {
            for (int i = 2; i <= n; i++)
            {
                printf("%lld ", d[i] - d[i - 1]);
            }
            puts("");
        }
        else
        {
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}