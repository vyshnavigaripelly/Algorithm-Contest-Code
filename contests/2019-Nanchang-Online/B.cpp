#include <iostream>
#include <cstring>
#include <queue>
#include <vector>

using namespace std;

const int N = 1007;
const int M = N * N;

int head[N], fire[N], ver[M], edge[M], Next[M];
int mp[N][N];
long long d[N];
bool v[N];
int s, st, n, m, tot;
queue<int> q1;

void add(int x, int y, int z)
{
    ver[tot] = y;
    edge[tot] = z;
    Next[tot] = head[x];
    head[x] = tot++;
}

long long spfa()
{
    long long ans = 0;
    while (q1.size())
        q1.pop();
    q1.push(s);
    memset(v, 0, sizeof(v));
    memset(d, 0x3f, sizeof(d));
    d[s] = 0;
    while (q1.size())
    {
        int x = q1.front();
        q1.pop();
        v[x] = 0;
        for (int i = head[x]; ~i; i = Next[i])
        {
            int y = ver[i];
            if (d[y] > d[x] + edge[i])
            {
                d[y] = d[x] + edge[i];
                if (!v[y])
                {
                    v[y] = 1;
                    q1.push(y);
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (i == s)
            continue;
        ans = max(ans, d[i]);
    }
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int c, q;
        memset(head, -1, sizeof(head));
        memset(mp, 0x3f, sizeof(mp));
        tot = 0;
        scanf("%d%d%d%d%d", &n, &m, &s, &q, &c);
        for (int i = 0; i < q; i++)
        {
            scanf("%d", &fire[i]);
        }
        for (int i = 0; i < m; i++)
        {
            int u, v, w;
            scanf("%d%d%d", &u, &v, &w);
            mp[u][v] = mp[v][u] = min(mp[u][v], w);
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                if (mp[i][j] != 0x3f3f3f3f)
                {
                    add(i, j, mp[i][j]);
                    add(j, i, mp[i][j]);
                }
            }
        }
        long long ans = spfa();
        //0超级源点  n + 1超级汇点
        for (int i = 0; i < q; i++)
        {
            add(0, fire[i], 0);
        }
        s = 0;
        long long now = spfa();
        long long cmp = now * c;
        if (ans > cmp)
        {
            ans = now;
        }
        printf("%lld\n", ans);
    }
    return 0;
}
