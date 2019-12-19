#include <iostream>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

priority_queue<int, vector<int>, greater<int>> q;

int ans[100007];

struct mys
{
    int l, r;
} node[100007];

int cmp(const mys &a, const mys &b)
{
    return a.l < b.l;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        while (!q.empty())
            q.pop();
        int n, m, trans = 0;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            q.push(i);
            ans[i] = 0;
        }
        for (int i = 0; i < m; i++)
            scanf("%d%d", &node[i].l, &node[i].r);
        sort(node, node + m, cmp);
        int tl = 1, tr = 0;
        for (int i = 0; i < m; i++)
        {
            trans = !trans;
            while (tl < node[i].l)
            {
                if (!ans[tl])
                    ans[tl] = 1;
                else
                    q.push(ans[tl]);
                tl++;
            }
            while (tr < node[i].r)
            {
                tr++;
                if (!ans[tr])
                {
                    ans[tr] = q.top();
                    q.pop();
                }
            }
        }
        printf("%d", ans[1]);
        for (int i = 2; i <= n; i++)
        {
            if (!ans[i])
                printf(" 1");
            else
                printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}