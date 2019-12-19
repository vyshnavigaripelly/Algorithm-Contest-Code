#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/hash_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

const int N = 1e6 + 7;

struct node
{
    int next, to;
} edge[N << 1];

int n, cnt;
int head[N], deg[N], vis[N];
long long usedCnt[N], ans[N];
vector<int> buc[N];
gp_hash_table<int, long long> finalBuc;

void add(int u, int v)
{
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    head[u] = cnt++;
}

void bfs()
{
    memset(deg, 0, (n + 1) * sizeof(int));
    memset(vis, 0, (n + 1) * sizeof(int));
    queue<int> q;
    q.push(n);
    while (q.size())
    {
        int u = q.front();
        q.pop();
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            deg[v]++;
            if (vis[v])
                continue;
            vis[v] = 1;
            q.push(v);
        }
    }
}

void tp()
{
    bfs();
    memset(usedCnt, 0, (n + 1) * sizeof(long long));
    queue<int> q;
    q.push(n);
    usedCnt[n] = 1;
    while (q.size())
    {
        int u = q.front();
        q.pop();
        if (head[u] == -1)
        {
            for (int i = 0; i < buc[u].size(); i++)
            {
                finalBuc[buc[u][i]] += usedCnt[u];
            }
            continue;
        }
        for (int i = head[u]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            usedCnt[v] += usedCnt[u];
            if (--deg[v] == 0)
            {
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
        cnt = 0;
        finalBuc.clear();
        scanf("%d", &n);
        memset(head, -1, (n + 1) * sizeof(int));
        for (int i = 1; i <= n; i++)
        {
            buc[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            int type;
            scanf("%d", &type);
            if (type == 1)
            {
                int m;
                scanf("%d", &m);
                for (int j = 0; j < m; j++)
                {
                    int num;
                    scanf("%d", &num);
                    buc[i].push_back(num);
                }
            }
            else
            {
                int x, y;
                scanf("%d %d", &x, &y);
                add(i, x);
                add(i, y);
            }
        }
        tp();
        long long sum = 0, maxn = -1;
        for (auto i : finalBuc)
        {
            sum += i.second;
            maxn = max(maxn, i.second);
        }
        sum -= maxn;
        if (maxn > sum)
        {
            printf("%lld\n", sum * 2);
        }
        else
        {
            printf("%lld\n", sum + maxn);
        }
    }
    return 0;
}