#include <iostream>
#include <cstring>
#include <vector>

#define maxn 100007

using namespace std;

struct node
{
    int id, to, next, vis;
} edge[maxn * 4];

int n, m, cnt, head[maxn], degree[maxn];
vector<int> ans[maxn];
bool vis[maxn];

void add(int u, int v, int id)
{
    edge[cnt].id = id;
    edge[cnt].vis = 0;
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void init()
{
    cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        head[i] = -1;
        degree[i] = 0;
        vis[i] = 0;
        ans[i].clear();
    }
}

void dfs(int u)
{
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to, id = edge[i].id;
        if (!edge[i].vis)
        {
            edge[i].vis = 1;
            edge[i ^ 1].vis = 1;
            dfs(v);
            if (id)
                ans[cnt].push_back(-id);
            else //存在欧拉通路，需要的士兵++
                cnt++;
        }
    }
}

int main()
{
    int u, v;
    while (~scanf("%d%d", &n, &m))
    {
        init();
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v, i);
            add(v, u, -i);
            degree[v]++;
            degree[u]++;
        }
        u = -1;
        for (int i = 1; i <= n; i++) //混合图加边
        {
            if (degree[i] % 2)
            {
                if (~u)
                {
                    u = i;
                    continue;
                }
                add(u, i, 0);
                add(i, u, 0);
                u = -1;
            }
        }
        cnt = 0;
        for (int i = 1; i <= n; i++) //找实边的欧拉回路
        {
            if (!(degree[i] % 2) && !vis[i])
            {
                vis[i] = 1;
                cnt++;
                dfs(i);
            }
        }
        for (int i = 1; i <= n; i++) //找加边后产生的欧拉回路
        {
            if (degree[i] && !vis[i])
            {
                vis[i] = 1;
                cnt++;
                dfs(i);
                cnt--;
            }
        }

        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i++)
        {
            printf("%d", ans[i].size());
            for (int j = 0; j < ans[i].size(); j++)
            {
                printf(" %d", ans[i][j]);
            }
            puts("");
        }
    }
    return 0;
}