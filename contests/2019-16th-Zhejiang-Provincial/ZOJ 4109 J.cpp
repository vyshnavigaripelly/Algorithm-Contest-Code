#include <iostream>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

priority_queue<int, vector<int>, greater<int>> wait;

const int N = 1e6 + 7;

vector<int> mp[N], ans;
int c[N], inq[N], used[N], vis[N];

void bfs(int u, int color)
{
    queue<int> q;
    q.push(u);
    vis[u] = 1;
    while (!q.empty())
    {
        int now = q.front();
        c[now] = color;
        q.pop();
        for (int i = 0; i < mp[now].size(); i++)
        {
            int v = mp[now][i];
            if (!vis[v])
            {
                vis[v] = 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m, a, b, unhappy = 0;
        scanf("%d%d", &n, &m);
        ans.clear();
        for (int i = 0; i <= n; i++)
        {
            inq[i] = 0;
            c[i] = i;
            used[i] = 0;
            vis[i] = 0;
            mp[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &a, &b);
            mp[a].push_back(b);
            mp[b].push_back(a);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
                bfs(i, c[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!used[c[i]])
            {
                used[c[i]] = 1;
                unhappy++;
                wait.push(i);
                inq[i] = 1;
            }
        }
        while (wait.size())
        {
            int now = wait.top();
            wait.pop();
            ans.push_back(now);
            for (int i = 0; i < mp[now].size(); i++)
            {
                int v = mp[now][i];
                if (!inq[v])
                {
                    inq[v] = 1;
                    wait.push(v);
                }
            }
        }
        printf("%d\n", unhappy);
        int s = ans.size();
        for (int i = 0; i < s; i++)
        {
            printf("%d", ans[i]);
            if (i != s - 1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
