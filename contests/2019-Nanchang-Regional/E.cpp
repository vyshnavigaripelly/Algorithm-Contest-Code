#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 7, M = 5e5 + 7;

struct Node
{
    int next, to, w;
} edge[M << 1];

struct White
{
    int u, v, w;
    int used;

    bool operator<(const White &b) const
    {
        return b.w < w;
    }
};

vector<White> whiteedge;
int head[N], root[N], fa[N];
int n, m, k, cnt;

int Find(int u)
{
    if (fa[u] < 0)
        return u;
    return fa[u] = Find(fa[u]);
}

void add(int u, int v, int w)
{
    edge[cnt].next = head[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    head[u] = cnt++;
}

void dfs(int u, int col)
{
    root[u] = col;
    for (int i = head[u]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (root[v] == -1)
            dfs(v, col);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(fa, -1, sizeof(fa));
        memset(root, -1, sizeof(root));
        memset(head, -1, sizeof(head));
        whiteedge.clear();
        cnt = 0;
        scanf("%d %d %d", &n, &m, &k);
        long long ans = 0;
        for (int i = 0; i < m; i++)
        {
            int u, v, w, c;
            scanf("%d %d %d %d", &u, &v, &w, &c);
            if (c == 0)
            {
                add(u, v, w);
                add(v, u, w);
                ans += w;
                int fau = Find(u), fav = Find(v);
                if (fau != fav)
                {
                    fa[fau] = fav;
                }
            }
            else if (c == 1)
            {
                whiteedge.push_back({u, v, w, 0});
            }
        }
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            if (root[i] == -1)
            {
                dfs(i, ++tot);
            }
        }
        sort(whiteedge.begin(), whiteedge.end());
        for (int i = 0; i < whiteedge.size(); i++)
        {
            int u = whiteedge[i].u, v = whiteedge[i].v, w = whiteedge[i].w;
            int fau = Find(u), fav = Find(v);
            if (fau != fav)
            {
                tot--;
                k--;
                fa[fau] = fav;
                ans += w;
                whiteedge[i].used = 1;
            }
        }
        if (k < 0 || tot > 1)
        {
            puts("-1");
        }
        else
        {
            for (int i = 0; i < whiteedge.size() && k > 0; i++)
            {
                if (whiteedge[i].used == 0)
                {
                    ans += whiteedge[i].w;
                    k--;
                    whiteedge[i].used = 1;
                }
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}