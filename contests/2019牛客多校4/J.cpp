#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct node
{
    int cnt, u;
    node(int cnt, int u) : cnt(cnt), u(u) {}
};

vector<pair<int, int>> mp[1007];
int n, m, s, t, k, d[1007][1007];

void bfs()
{
    d[0][s] = 0;
    queue<node> Q;
    Q.push(node(0, s));
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        for (int i = 0; i < mp[now.u].size(); i++)
        {
            int v = mp[now.u][i].first, w = mp[now.u][i].second;
            if (now.cnt < k)
            {
                if (d[now.cnt + 1][v] > d[now.cnt][now.u])
                {
                    d[now.cnt + 1][v] = d[now.cnt][now.u];
                    Q.push(node(now.cnt + 1, v));
                }
            }
            if (d[now.cnt][v] > d[now.cnt][now.u] + w)
            {
                d[now.cnt][v] = d[now.cnt][now.u] + w;
                Q.push(node(now.cnt, v));
            }
        }
    }
}

int main()
{
    memset(d, 0x3f, sizeof(d));
    cin >> n >> m >> s >> t >> k;
    int u, v, w;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        mp[u].push_back(make_pair(v, w));
        mp[v].push_back(make_pair(u, w));
    }
    bfs();
    cout << d[k][t] << endl;
    return 0;
}