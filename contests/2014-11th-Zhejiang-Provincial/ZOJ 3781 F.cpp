#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int dir[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};

int n, m, c, co[1605], cnt, fa[40][40], head[1605];
int apper[1605][1605];
char mp[45][45];

struct node
{
    int w;
    int to;
    int next;
} edge[1605 * 1605];

struct mys
{
    int pt;
    int w;
    mys(int pt, int w) : pt(pt), w(w) {}
};

void add(int u, int v)
{
    edge[c].to = v;
    edge[c].next = head[u];
    head[u] = c++;
}

void dfs(int cx, int cy, char ch)
{
    for (int i = 0; i < 4; i++)
    {
        int dx = cx + dir[i][0];
        int dy = cy + dir[i][1];
        if (dx > -1 && dx < n && dy > -1 && dy < m)
        {
            if (mp[dx][dy] == ch)
            {
                if (!fa[dx][dy])
                {
                    fa[dx][dy] = cnt;
                    dfs(dx, dy, ch);
                }
            }
            else if (fa[dx][dy])
            {
                if (!apper[cnt][fa[dx][dy]])
                {
                    add(cnt, fa[dx][dy]);
                    add(fa[dx][dy], cnt);
                    apper[cnt][fa[dx][dy]] = 1;
                    apper[fa[dx][dy]][cnt] = 1;
                }
            }
        }
    }
}

int bfs(int st)
{
    int maxn = 0;
    bool inq[1605] = {0};
    queue<mys> Q;
    mys t(st, 0);
    Q.push(t);
    inq[st] = 1;

    while (!Q.empty())
    {
        mys now = Q.front();
        Q.pop();
        maxn = max(maxn, now.w);

        for (int i = head[now.pt]; ~i; i = edge[i].next)
        {
            int v = edge[i].to;
            if (inq[v] || v == now.pt)
                continue;
            mys tt(v, now.w + 1);
            Q.push(tt);
            inq[v] = 1;
        }
    }

    return maxn;
}

void init()
{
    memset(fa, 0, sizeof(fa));
    memset(head, -1, sizeof(head));
    cnt = 0;
    c = 0;
    memset(apper, 0, sizeof(apper));
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int ans = 1605;
        init();
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%s", &mp[i]);
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!fa[i][j])
                {
                    fa[i][j] = ++cnt;
                    dfs(i, j, mp[i][j]);
                }
            }
        }

        //cout << "缩点 " << cnt << endl;

        for (int i = 1; i <= cnt; i++)
        {
            ans = min(ans, bfs(i));
        }
        printf("%d\n", ans);
    }
    return 0;
}