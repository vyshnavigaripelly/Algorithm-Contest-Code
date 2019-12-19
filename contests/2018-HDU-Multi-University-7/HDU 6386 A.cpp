#include <iostream>
#include <vector>
#include <cstring>
#include <queue>

#define maxn 100007

using namespace std;

int n, m, cnt;
int d[maxn];
int inq[maxn];
vector<pair<int, int>> mp[maxn];

struct node
{
    int weight;
    int pos;
    node(int weight, int pos) : weight(weight), pos(pos) {}
};

void init()
{
    memset(d, 0x3f, (n + 1) * sizeof(int));
    memset(inq, 0, (n + 1) * sizeof(int));
    for (int i = 1; i <= n; i++)
        mp[i].clear();
    cnt = 0;
}

void spfa()
{
    queue<node> q;
    q.push(node(-1, 1));
    d[1] = 0;
    inq[1] = 1;
    while (!q.empty())
    {
        node now = q.front();
        q.pop();
        inq[now.pos] = 0;
        for (int i = 0; i < mp[now.pos].size(); i++)
        {
            int v = mp[now.pos][i].first;
            int w = mp[now.pos][i].second;
            if (w == now.weight)
            {
                if (d[v] > d[now.pos])
                {
                    d[v] = d[now.pos];
                    if (!inq[v])
                    {
                        inq[v] = 1;
                        q.push(node(w, v));
                    }
                }
            }
        }
        for (int i = 0; i < mp[now.pos].size(); i++)
        {
            int v = mp[now.pos][i].first;
            int w = mp[now.pos][i].second;
            if (d[v] > d[now.pos] + 1)
            {
                d[v] = d[now.pos] + 1;
                if (!inq[v])
                {
                    inq[v] = 1;
                    q.push(node(w, v));
                }
            }
        }
    }
}

int main()
{
    while (~scanf("%d%d", &n, &m))
    {
        int u, v, w;
        init();
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            mp[u].push_back(make_pair(v, w));
            mp[v].push_back(make_pair(u, w));
        }
        spfa();
        if (d[n] == 0x3f3f3f3f)
            printf("-1\n");
        else
            printf("%d\n", d[n]);
    }
    return 0;
}