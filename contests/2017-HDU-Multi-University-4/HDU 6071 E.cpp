#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

int minw;
long long k, dis[5][60007];
vector<pair<int, int>> mp[5];

struct node
{
    int u;
    int mod;
    node(int u, int mod) : u(u), mod(mod) {}
};

void spfa()
{
    memset(dis, 0x3f, sizeof(dis));
    queue<node> Q;
    dis[2][0] = 0;
    Q.push(node(2, 0));
    while (!Q.empty())
    {
        node now = Q.front();
        Q.pop();
        for (int i = 0; i < 2; i++)
        {
            int v = mp[now.u][i].first, w = mp[now.u][i].second, next = (now.mod + w) % minw;
            if (dis[v][next] > dis[now.u][now.mod] + w)
            {
                dis[v][next] = dis[now.u][now.mod] + w;
                Q.push(node(v, next));
            }
        }
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long ans = 0x3f3f3f3f3f3f3f3f;
        for (int i = 1; i <= 4; i++)
            mp[i].clear();
        int d[5];
        cin >> k;
        for (int i = 1; i <= 4; i++)
        {
            cin >> d[i];
            mp[i].push_back(make_pair((i == 4 ? 1 : (i + 1)), d[i]));
            mp[(i == 4 ? 1 : (i + 1))].push_back(make_pair(i, d[i]));
        }
        minw = min(d[1], d[2]) * 2;
        spfa();
        for (int i = 0; i <= minw; i++)
        {
            if (dis[2][i] > k)
                ans = min(ans, dis[2][i]);
            else
            {
                long long tmp = ((k - dis[2][i]) + minw - 1) / minw * minw + dis[2][i];
                ans = min(tmp, ans);
            }
        }
        cout << ans << endl;
    }

    return 0;
}