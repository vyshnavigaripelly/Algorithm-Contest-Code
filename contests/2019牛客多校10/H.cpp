#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

vector<int> mp[10];
int flag;

void dfs(int u, int fa, int dep)
{
    if (dep == 4)
    {
        flag = 1;
        return;
    }
    for (int i = 0; i < mp[u].size() && !flag; i++)
    {
        int v = mp[u][i];
        if (v == fa)
            continue;
        dfs(v, u, dep + 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int deg[10] = {0};
        for (int i = 0; i < 10; i++)
            mp[i].clear();
        int st = -1;
        for (int i = 0; i < 5; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            mp[u].push_back(v);
            mp[v].push_back(u);
            deg[u]++;
            deg[v]++;
            if (deg[u] == 3)
                st = u;
            if (deg[v] == 3)
                st = v;
        }
        sort(deg + 1, deg + 7, greater<int>());
        if (deg[1] == 4)
        {
            puts("2,2-dimethylbutane");
            continue;
        }
        if (deg[1] == 3 && deg[2] == 3)
        {
            puts("2,3-dimethylbutane");
            continue;
        }
        if (deg[1] == 2)
        {
            puts("n-hexane");
            continue;
        }
        flag = 0;
        dfs(st, -1, 1);
        if (flag)
            puts("2-methylpentane");
        else
            puts("3-methylpentane");
    }
    return 0;
}