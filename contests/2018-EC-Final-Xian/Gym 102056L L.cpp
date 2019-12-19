#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int N = 1e5 + 7;

int pt[2], arr[N], con[N], ans[N], c[N], flag;
vector<int> mp[N];

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        pt[arr[i]]++;
    }
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        mp[u].push_back(v);
        mp[v].push_back(u);
        if (arr[u] != arr[v])
        {
            con[u] = con[v] = 1;
            flag = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (con[i])
        {
            c[arr[i]]++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int cnt = 0;
        int used[N] = {0};
        ans[i] = pt[arr[i]] - 1;
        for (int j = 0; j < mp[i].size(); j++)
        {
            int v = mp[i][j];
            if (arr[v] != arr[i] && !used[v])
            {
                used[v] = 1;
                ans[i]++;
                if (con[v])
                {
                    cnt++;
                }
            }
        }
        int tmp = ans[i] + 1;
        if (con[i])
        {
            ans[i] += (n - 1 - ans[i]) * 2;
        }
        else if (flag)
        {
            tmp += c[1 - arr[i]] - cnt;
            ans[i] += (c[1 - arr[i]] - cnt) * 2;
            ans[i] += (n - tmp) * 3;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", ans[i]);
    }
    return 0;
}