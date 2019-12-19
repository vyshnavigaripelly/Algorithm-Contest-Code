#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

struct node
{
    int next, to, w;
    node(int next, int to, int w) : next(next), to(to), w(w) {}
    node() {}
} edge[N << 2];

long long ans;
int head[N], deg[N];
int n, cnt;

void add(int u, int v, int w)
{
    edge[cnt] = node(head[u], v, w);
    head[u] = cnt++;
}

void dfs(int u, int fa)
{
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (v == fa)
            continue;
        if (deg[v] > 1)
        {
            int minn = 0x3f3f3f3f;
            long long sum = 0;
            for (int j = head[v]; ~j; j = edge[j].next)
            {
                minn = min(edge[j].w, minn);
                sum += edge[j].w;
            }
            ans += (1LL * minn * (deg[v] - 2) + sum);
        }
        dfs(v, u);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        cnt = 0;
        ans = 0;
        memset(deg, 0, (n + 1) * sizeof(int));
        memset(head, -1, (n + 1) * sizeof(int));
        for (int i = 0; i < n - 1; i++)
        {
            int u, v, w;
            scanf("%d %d %d", &u, &v, &w);
            deg[u]++;
            deg[v]++;
            add(u, v, w);
            add(v, u, w);
        }
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 1)
            {
                dfs(i, -1);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}