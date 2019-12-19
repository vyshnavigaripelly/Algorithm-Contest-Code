#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <iomanip>

using namespace std;

const int M = 1e6 + 7;
const int N = 1e5 + 7;

struct e
{
    int u, v, w;
    bool operator<(const e &a) const
    {
        return a.w > w;
    }
} edge[M];

struct node
{
    int next;
    int to;
    int w;
} ed[M << 1];

int bcj[N], head[N], SIZE[N];
int n, m, cnt;
long long wgcnt;

void add(int u, int v, int w)
{
    ed[cnt].next = head[u];
    ed[cnt].to = v;
    ed[cnt].w = w;
    head[u] = cnt++;
}

int Find(int x)
{
    if (bcj[x] < 0)
        return x;
    return bcj[x] = Find(bcj[x]);
}

long long kruskal()
{
    long long ans = 0;
    int num = 0;
    for (int i = 0; i < m; i++)
    {
        int u = Find(edge[i].u), v = Find(edge[i].v);
        if (u == v)
            continue;
        bcj[u] = v;
        add(edge[i].u, edge[i].v, edge[i].w);
        add(edge[i].v, edge[i].u, edge[i].w);
        ans += edge[i].w;
        if (++num == n - 1)
            break;
    }
    return ans;
}

void dfs(int u, int fa, int prew)
{
    SIZE[u] = 1;
    for (int i = head[u]; ~i; i = ed[i].next)
    {
        int v = ed[i].to, w = ed[i].w;
        if (v == fa)
            continue;
        dfs(v, u, w);
        SIZE[u] += SIZE[v];
    }
    if (fa != -1)
    {
        wgcnt += (1LL * SIZE[u] * (n - SIZE[u]) * prew);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(bcj, -1, sizeof(bcj));
        memset(head, -1, sizeof(head));
        wgcnt = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
        }
        sort(edge, edge + m);
        long long ans1 = kruskal();
        dfs(1, -1, 0);
        printf("%lld %.2f\n", ans1, 1.0 * wgcnt / (1LL * n * (n - 1) / 2));
    }
    return 0;
}