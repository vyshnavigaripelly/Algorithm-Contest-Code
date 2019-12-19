#include <iostream>
#include <cstdio>
#include <queue>
#include <cstring>

using namespace std;

const int maxn = 1e5 + 7;

struct
{
    int next, to;
} edge[maxn * 2];

int n, m, vis[maxn], cnt, head[maxn], ans[maxn];

void add(int u, int v)
{
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt;
    cnt++;
}

void solve()
{
    priority_queue<int, vector<int>, greater<int>> que;
    que.push(1);
    vis[1] = 1;
    int tar = 0;
    while (tar != n)
    {
        int now = que.top();
        que.pop();
        ans[tar] = now;
        tar++;
        for (int i = head[now]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (vis[v] == 0)
            {
                que.push(v);
                vis[v] = 1;
            }
        }
    }
}

int main()
{
    memset(head, -1, sizeof(head));
    int u, v;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        scanf("%d %d", &u, &v);
        add(u, v);
        add(v, u);
    }
    solve();
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}