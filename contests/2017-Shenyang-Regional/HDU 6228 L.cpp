#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

vector<int> mp[1000007];
int n, k, ans;
int sub[1000007];

void init()
{
    for (int i = 1; i <= n; i++)
    {
        mp[i].clear();
    }
    ans = 0;
    memset(sub, 0, sizeof(sub));
}

void dfs(int now, int pre)
{
    sub[now] = 1;
    for (int i = 0; i < mp[now].size(); i++)
    {
        int v = mp[now][i];
        if (v == pre)
            continue;
        dfs(v, now);
        sub[now] += sub[v];
        if (sub[v] >= k && (n - sub[v]) >= k)
            ans++;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        init();
        cin >> n >> k;
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            mp[u].push_back(v);
            mp[v].push_back(u); //无向图
        }
        dfs(1, 0);
        cout << ans << endl;
    }
    return 0;
}