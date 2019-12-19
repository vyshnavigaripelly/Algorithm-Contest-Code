#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 1010;
const int INF = 0x3f3f3f3f;

bool vis[MAXN];
int pre[MAXN];

int cost[MAXN][MAXN];
int ans[MAXN];

void Dijkstra(int cost[][MAXN], int lowcost[], int n, int start)
{
    for (int i = 0; i < n; i++)
    {
        lowcost[i] = INF;
        vis[i] = false;
        pre[i] = -1;
    }
    lowcost[start] = 0;
    for (int i = 0; i < n; i++)
    {
        int k = -1;
        int Min = INF;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowcost[j] < Min)
            {
                Min = lowcost[j];
                k = j;
            }
        }
        if (k == -1)
        {
            break;
        }
        vis[k] = true;
        for (int j = 0; j < n; j++)
        {
            if (!vis[j] && lowcost[k] + cost[k][j] < lowcost[j])
            {
                lowcost[j] = lowcost[k] + cost[k][j];
                pre[j] = k;
            }
        }
    }
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(cost, 0x3f, sizeof(cost));
        while (m--)
        {
            int u, v, w;
            cin >> u >> v >> w;
            cost[u][v] = cost[v][u] = min(cost[u][v], w);
        }
        int beg, end;
        cin >> beg >> end;
        Dijkstra(cost, ans, n, beg);
        cout << (ans[end] >= INF ? -1 : ans[end]) << endl;
    }
    return 0;
}