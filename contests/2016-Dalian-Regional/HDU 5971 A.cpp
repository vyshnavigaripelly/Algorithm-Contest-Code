#include <cstdio>
#include <algorithm>
using namespace std;

#define maxn 22000

struct node
{
    int u, v;
    int next;
    int to;
} edge[maxn];

int cnt, head[maxn], col[maxn], flag, n, m, x, y;

void add(int u, int v)
{
    edge[cnt].to = v;
    edge[cnt].next = head[u];
    head[u] = cnt++;
}

void dfs(int x, int pre, int color)
{
    col[x] = color;
    for (int i = head[x]; ~i; i = edge[i].next)
    {
        int v = edge[i].to;
        if (pre == v)
            continue;
        if (col[v] == col[x])
        {
            flag = 0;
            return;
        }
        if (!col[v])
            dfs(v, x, -color);
    }
}

int main()
{
    int u, v;
    while (~scanf("%d%d%d%d", &n, &m, &x, &y))
    {
        memset(head, -1, sizeof(head));
        memset(col, 0, sizeof(col));
        cnt = 0;
        flag = 1;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &u, &v);
            add(u, v);
            add(v, u);
        }
        for (int i = 0; i < x; i++)
        {
            scanf("%d", &u);
            col[u] = 1;
        }
        for (int i = 0; i < y; i++)
        {
            scanf("%d", &u);
            col[u] = -1;
        }
        for (int i = 1; i <= n; i++)
        {
            if (col[i])
                dfs(i, 0, col[i]);
        }
        for (int i = 1; i <= n && flag; i++)
        {
            if (!col[i] && head[i] != -1)
                dfs(i, 0, 1);
        }
        for (int i = 1; i <= n; i++)
        {
            if (!col[i])
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}