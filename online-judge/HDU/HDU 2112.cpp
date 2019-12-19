#include <iostream>
#include <cstring>
#include <queue>
#include <map>
#include <vector>
#include <string>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 10007;

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

int main()
{
    int m;
    while (cin >> m && m != -1)
    {
        for (int i = 0; i <= m; i++)
        {
            E[i].clear();
        }
        int n = 0;
        memset(cost, 0x3f, sizeof(cost));
        map<string, int> mp;
        string beg, end;
        cin >> beg >> end;
        mp[beg] = ++n;
        mp[end] = ++n;
        while (m--)
        {
            string u, v;
            int w;
            cin >> u >> v >> w;
            if (mp[u] == 0)
            {
                mp[u] = ++n;
            }
            if (mp[v] == 0)
            {
                mp[v] = ++n;
            }
            addedge(mp[u], mp[v], w);
            addedge(mp[v], mp[u], w);
        }
        Dijkstra(mp[beg]);
        cout << (cost[mp[end]] >= INF ? -1 : cost[mp[end]]) << endl;
    }
    return 0;
}