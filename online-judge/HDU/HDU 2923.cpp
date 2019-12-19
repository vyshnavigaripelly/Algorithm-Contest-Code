#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <numeric>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 107;
const int MAXM = 20007;

struct qnode
{
    int v;
    int c;
    qnode(int _v = 0, int _c = 0) : v(_v), c(_c) {}
    bool operator<(const qnode &r) const
    {
        return c > r.c;
    }
};

struct Edge
{
    int v, w;
    Edge(int _v = 0, int _w = 0) : v(_v), w(_w) {}
};

vector<Edge> E[MAXN];
bool vis[MAXN];
int cost[MAXN];

void Dijkstra(int start)
{
    memset(vis, false, sizeof(vis));
    memset(cost, 0x3f, sizeof(cost));
    priority_queue<qnode> que;
    cost[start] = 0;
    que.push(qnode(start, 0));
    qnode tmp;
    while (!que.empty())
    {
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if (vis[u])
            continue;
        vis[u] = true;
        for (int i = 0; i < E[u].size(); i++)
        {
            int v = E[tmp.v][i].v;
            int w = E[u][i].w;
            if (!vis[v] && cost[v] > cost[u] + w)
            {
                cost[v] = cost[u] + w;
                que.push(qnode(v, cost[v]));
            }
        }
    }
}

void addedge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w));
}

int u[MAXM], v[MAXM], w[MAXM];

int main()
{
    int n, c, m, cas = 1;
    while (cin >> n >> c >> m && (n || c || m))
    {
        for (int i = 0; i <= 2 * m; i++)
        {
            E[i].clear();
        }
        memset(cost, 0x3f, sizeof(cost));
        n = 0;
        int cnt = 0;
        map<string, int> mp;
        string beg;
        cin >> beg;
        mp[beg] = ++n;
        for (int i = 0; i < c; i++)
        {
            string car;
            cin >> car;
            mp[car] = ++n;
        }
        while (m--)
        {
            char a[15], b[15], d1[3], d2[3];
            int ww;
            scanf("%s %2s %d %2s %s", a, d1, &ww, d2, b);
            if (mp[a] == 0)
            {
                mp[a] = ++n;
            }
            if (mp[b] == 0)
            {
                mp[b] = ++n;
            }
            if (d2[1] == '>')
            {
                u[cnt] = mp[a];
                v[cnt] = mp[b];
                w[cnt++] = ww;
                addedge(mp[a], mp[b], ww);
            }
            if (d1[0] == '<')
            {
                u[cnt] = mp[b];
                v[cnt] = mp[a];
                w[cnt++] = ww;
                addedge(mp[b], mp[a], ww);
            }
        }
        Dijkstra(mp[beg]);
        int ans = 0;
        ans += accumulate(&cost[mp[beg]], &cost[mp[beg]] + c + 1, 0);
        cout << ans << endl;
        for (int i = 0; i <= 2 * m; i++)
        {
            E[i].clear();
        }
        memset(cost, 0x3f, sizeof(cost));
        for (int i = 0; i < cnt; i++)
        {
            addedge(v[i], u[i], w[i]);
        }
        Dijkstra(mp[beg]);
        ans += accumulate(&cost[mp[beg]], &cost[mp[beg]] + c + 1, 0);
        cout << cas << ": " << ans << endl;
        cas++;
    }
    return 0;
}