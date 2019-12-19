#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

#define maxn 100007

using namespace std;

struct node
{
    long long a, b;
    int id;
    bool operator<(const node &n) const
    {
        return min(-a, -a + b - n.a) < min(-n.a, -n.a + n.b - a);
    }
} mon[maxn];

int fa[maxn];
bool vis[maxn];
vector<int> mp[maxn];
priority_queue<node> q;

void dfs(int u, int pre)
{
    fa[u] = pre;
    for (int i = 0; i < mp[u].size(); i++)
    {
        int v = mp[u][i];
        if (v != pre)
        {
            dfs(v, u);
        }
    }
}

int Find(int x)
{
    if (!vis[fa[x]])
        return fa[x];
    return fa[x] = Find(fa[x]);
}

void init(int n)
{
    for (int i = 1; i <= n; i++)
    {
        fa[i] = i;
        mp[i].clear();
        vis[i] = 0;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, u, v;
        scanf("%d", &n);
        init(n);
        mon[1].a = 0, mon[1].b = 0, mon[1].id = 1;
        for (int i = 2; i <= n; i++)
        {
            scanf("%lld%lld", &mon[i].a, &mon[i].b);
            mon[i].id = i;
            q.push(mon[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%d%d", &u, &v);
            mp[u].push_back(v);
            mp[v].push_back(u);
        }
        dfs(1, 1);
        while (!q.empty())
        {
            node now = q.top();
            q.pop();
            if (vis[now.id] || (mon[now.id].a != now.a || mon[now.id].b != now.b))
                continue;
            vis[now.id] = 1;
            int f = Find(now.id);
            //父节点的继承需要修改
            if (mon[f].b - mon[now.id].a < 0)
            {
                mon[f].a -= (mon[f].b - mon[now.id].a);
                mon[f].b = mon[now.id].b;
            }
            else
            {
                mon[f].b += (mon[now.id].b - mon[now.id].a);
            }
            if (f != 1)
                q.push(mon[f]);
        }
        printf("%lld\n", mon[1].a);
    }
    return 0;
}