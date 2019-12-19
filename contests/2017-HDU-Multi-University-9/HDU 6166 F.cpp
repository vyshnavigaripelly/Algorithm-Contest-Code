#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
#include <cstdio>

using namespace std;

const int N = 100007;

struct
{
    int w;
    int next;
    int to;
} edge[N];

struct node
{
    long long u, w;
    node(long long u, long long w) : u(u), w(w) {}
    bool operator<(const node &a) const
    {
        return w > a.w;
    }
};

int n, m, k, cnt;
int head[N], vis[N], tar[N], color[N];
long long d[N], ans;
priority_queue<node> q;

void add(int u, int v, int w)
{
    edge[cnt].next = head[u];
    edge[cnt].w = w;
    edge[cnt].to = v;
    head[u] = cnt++;
}

void dijkstra()
{
    memset(d, 0x3f, (n + 1) * sizeof(long long));
    memset(vis, 0, (n + 1) * sizeof(int));
    for (int i = 0; i < k; i++)
    {
        if (!color[i])
        {
            d[tar[i]] = 0;
            q.push(node(tar[i], 0));
        }
    }
    while (q.size())
    {
        int now = q.top().u;
        q.pop();
        if (vis[now])
            continue;
        vis[now] = 1;
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int v = edge[i].to, w = edge[i].w;
            if (d[v] > d[now] + w)
            {
                d[v] = d[now] + w;
                q.push(node(v, d[v]));
            }
        }
    }
    for (int i = 0; i < k; i++)
    {
        if (color[i])
        {
            ans = min(d[tar[i]], ans);
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        cnt = 0;
        ans = 0x3f3f3f3f3f3f3f3f;
        scanf("%d %d", &n, &m);
        memset(head, -1, (n + 1) * sizeof(int));
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            add(u, v, w);
        }
        scanf("%d", &k);
        for (int i = 0; i < k; i++)
        {
            scanf("%d", &tar[i]);
        }
        sort(tar, tar + k);
        int last = 0;
        for (int i = 0; i < 20; i++)
        {
            if ((tar[k - 1] >> i) & 1)
            {
                last = i;
            }
        }
        for (int i = 0; i <= last; i++)
        {
            for (int j = 0; j < k; j++)
            {
                if ((tar[j] >> i) & 1)
                    color[j] = 1;
                else
                    color[j] = 0;
            }
            dijkstra();
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}