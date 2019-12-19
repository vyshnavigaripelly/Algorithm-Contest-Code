#include <iostream>
#include <cstring>
#include <vector>>
#include <algorithm>
#include <queue>
#include <functional>

#define inf 0x3f3f3f3f3f3f3f3f
#define N 100007

using namespace std;

int cnt[N], n, m, t, k, s, vis[N];
long long d[N];

struct node
{
    int u;
    long long w;
    node(int uu, long long ww) : u(uu), w(ww) {}
};

vector<node> g[N];

void SPFA()
{
    int i;
    for (i = 0; i <= n; i++)
    {
        d[i] = inf;
        vis[i] = 0;
    }
    d[t] = 0;
    queue<int> que;
    que.push(t);
    vis[t] = 1;
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        vis[u] = 0;
        for (i = 0; i < g[u].size(); i++)
        {
            node b = g[u][i];
            int v = b.u;
            if (d[v] > d[u] + b.w)
            {
                d[v] = d[u] + b.w;
                if (!vis[v])
                {
                    vis[v] = 1;
                    que.push(v);
                }
            }
        }
    }
}

struct cnode
{
    int u;
    long long len;
    cnode(int uu, long long ww) : u(uu), len(ww) {}
    friend bool operator<(cnode a, cnode b) //重载比较运算符
    {
        return a.len + d[a.u] > b.len + d[b.u]; //g(x)=a.len,h(x)=d[a.u]
    }
};

long long A_star()
{
    int i;
    if (d[s] == inf)
        return -1; //若s到t不连通的话，提前终止
    priority_queue<cnode> que;

    memset(cnt, 0, sizeof(cnt));
    que.push(cnode(s, 0));
    while (!que.empty())
    {
        cnode a = que.top();
        que.pop();
        int u = a.u;
        long long len = a.len;
        cnt[u]++;
        if (cnt[t] == k)
            return len;
        for (i = 0; i < g[u].size(); i++)
        {
            node b = g[u][i];
            int v = b.u;
            que.push(cnode(v, len + b.w));
        }
    }
    return -1;
}

int main()
{
    int cas;
    scanf("%d", &cas);
    while (cas--)
    {
        scanf("%d%d", &n, &m);
        t = n, s = 1, k = 2;
        int mine = 0x3f3f3f3f;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        int u, v, w;
        while (m--)
        {
            scanf("%d%d%d", &u, &v, &w);
            mine = min(mine, w);
            g[u].push_back(node(v, w));
            g[v].push_back(node(u, w));
        }
        SPFA();
        long long ans = A_star();
        if (ans == -1)
        {
            printf("%lld\n", d[1] + 2 * mine);
        }
        else
            printf("%lld\n", ans);
    }
    return 0;
}