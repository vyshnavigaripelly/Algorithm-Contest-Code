#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 0x3f3f3f3f;
const int MAXN = 550;
int dist[MAXN];

struct Edge
{
    int u, v;
    int cost;
    Edge(int _u = 0, int _v = 0, int _cost = 0) : u(_u), v(_v), cost(_cost) {}
};

vector<Edge> E;

bool Bellman(int n)
{
    for (int i = 1; i <= n; i++)
        dist[i] = INF;
    for (int i = 1; i < n; i++)
    {
        bool flag = false;
        for (int j = 0; j < E.size(); j++)
        {
            int u = E[j].u;
            int v = E[j].v;
            int cost = E[j].cost;
            if (dist[v] > dist[u] + cost)
            {
                dist[v] = dist[u] + cost;
                flag = true;
            }
        }
        if (!flag)
            return true;
    }
    for (int j = 0; j < E.size(); j++)
        if (dist[E[j].v] > dist[E[j].u] + E[j].cost)
            return false;
    return true;
}

void addedge(int u, int v, int w)
{
    E.push_back(Edge(u, v, w));
}

int main()
{
    int f;
    cin >> f;
    while (f--)
    {
        int n, m, wh;
        cin >> n >> m >> wh;
        int u, v, w;
        E.clear();
        while (m--)
        {
            cin >> u >> v >> w;
            addedge(u, v, w);
            addedge(v, u, w);
        }
        while (wh--)
        {
            cin >> u >> v >> w;
            addedge(u, v, -w);
        }
        if (Bellman(n))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}