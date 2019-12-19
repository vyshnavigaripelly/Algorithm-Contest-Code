#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>

using namespace std;

struct node
{
    int w;
    int to;
    int next;
} edge[1005];

int n, m, cnt;
int head[35], d[35];

void add(int u, int v, int w)
{
    edge[cnt].w = w;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void SPFA(int skip)
{
    bool vis[35] = {0};
    queue<int> Q;
    Q.push(1);
    d[1] = 0;
    vis[1] = 1;
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        vis[now] = 0;
        if (now == skip)
        {
            continue;
        }
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (v == skip)
                continue;
            if (d[now] + edge[i].w < d[v])
            {
                d[v] = d[now] + edge[i].w;
                if (vis[v])
                    continue;
                Q.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    while (cin >> n >> m && (n || m))
    {
        cnt = 0;
        memset(head, -1, sizeof(head));
        int u, v, w, maxn = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        for (int i = 2; i < n; i++)
        {
            memset(d, 0x3f, sizeof(d));
            SPFA(i);
            maxn = max(d[n], maxn);
        }
        if (maxn != 0x3f3f3f3f)
            cout << maxn << endl;
        else
            cout << "Inf" << endl;
    }
    return 0;
}