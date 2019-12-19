#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <cstring>

const int N = 1007;
const int M = 6007;

using namespace std;

int cnt, ptcnt, tot, n, m, flag, num;
int low[N], dfn[N], head[N], root[N], vis[N], used[N][N], in[N];
vector<int> mp[N];
stack<int> stk;

struct
{
    int to;
    int next;
} edge[M];

void add(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void init()
{
    for (int i = 0; i <= n; i++)
    {
        vis[i] = 0, head[i] = -1, dfn[i] = 0, low[i] = 0, root[i] = 0, cnt = 0, tot = 0, ptcnt = 0;
        mp[i].clear();
    }
}

void tarjan(int u)
{
    low[u] = dfn[u] = ++tot;
    stk.push(u);
    vis[u] = 1;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else if (vis[v])
            low[u] = min(dfn[v], low[u]);
    }
    if (low[u] == dfn[u])
    {
        ptcnt++;
        while (true)
        {
            int now = stk.top();
            stk.pop();
            vis[now] = 0;
            root[now] = ptcnt;
            if (now == u)
                break;
        }
    }
}

void dfs(int u, int num)
{
    if (num == ptcnt)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < mp[u].size() && !flag; i++)
    {
        int v = mp[u][i];
        dfs(v, num + 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d %d", &n, &m);
        init();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
        }
        while (stk.size())
            stk.pop();
        for (int i = 1; i <= n; i++)
        {
            if (!dfn[i])
                tarjan(i);
        }
        for (int i = 1; i <= ptcnt; i++)
        {
            memset(used[i], 0, (ptcnt + 1) * sizeof(int));
            in[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = head[i]; ~j; j = edge[j].next)
            {
                int v = edge[j].to;
                if (root[i] != root[v] && !used[root[i]][root[v]])
                {
                    in[root[v]]++;
                    mp[root[i]].push_back(root[v]);
                    used[root[i]][root[v]] = 1;
                }
            }
        }
        int st = 1;
        flag = 0;
        for (int i = 1; i <= ptcnt; i++)
        {
            if (in[i] == 0)
            {
                st = i;
                flag++;
            }
        }
        if (flag > 1)
        {
            puts("Light my fire!");
            continue;
        }
        flag = 0;
        dfs(st, 1);
        if (flag)
            puts("I love you my love and our love save us!");
        else
            puts("Light my fire!");
    }
    return 0;
}