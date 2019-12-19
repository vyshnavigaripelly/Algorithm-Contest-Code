#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <numeric>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 1000007;

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
    int v, cost;
    Edge(int _v = 0, int _cost = 0) : v(_v), cost(_cost) {}
};

vector<Edge> E[MAXN];
bool vis[MAXN];
int lowcost[MAXN];

void Dijkstra(int n, int start)
{
    memset(vis, false, sizeof(vis));
    memset(lowcost, 0x3f, sizeof(lowcost));
    priority_queue<qnode> que;
    lowcost[start] = 0;
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
            int cost = E[u][i].cost;
            if (!vis[v] && lowcost[v] > lowcost[u] + cost)
            {
                lowcost[v] = lowcost[u] + cost;
                que.push(qnode(v, lowcost[v]));
            }
        }
    }
}

void addedge(int u, int v, int w)
{
    E[u].push_back(Edge(v, w));
}

int u[MAXN], v[MAXN], w[MAXN];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i <= n; i++)
        {
            E[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            cin >> u[i] >> v[i] >> w[i];
            addedge(u[i], v[i], w[i]);
        }
        long long ans = 0;
        Dijkstra(n, 1);
        ans += accumulate(lowcost + 1, lowcost + 1 + n, 0);
        for (int i = 0; i <= n; i++)
        {
            E[i].clear();
        }
        for (int i = 0; i < m; i++)
        {
            addedge(v[i], u[i], w[i]);
        }
        Dijkstra(n, 1);
        ans += accumulate(lowcost + 1, lowcost + 1 + n, 0);
        cout << ans << endl;
    }
    return 0;
}