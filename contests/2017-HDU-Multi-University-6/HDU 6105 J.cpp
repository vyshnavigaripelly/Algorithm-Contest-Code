#include <iostream>
#include <vector>

using namespace std;

int fa[507], leaf[507], size[507], cnt[507];
int n, k;
vector<int> tree[507];

void dfs(int u)
{
    size[u] = 1;
    for (int i = 0; i < tree[u].size(); i++)
    {
        int v = tree[u][i];
        dfs(v);
        size[u] += size[v];
    }
    if (size[u] == 1)
        leaf[u] = 1;
}

void init()
{
    for (int i = 1; i <= n; i++)
    {
        leaf[i] = 0;
        tree[i].clear();
        cnt[i] = 0;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int flag = 0;
        cin >> n >> k;
        init();
        for (int i = 2; i <= n; i++)
        {
            int v;
            cin >> v;
            fa[i] = v;
            tree[v].push_back(i);
        }
        dfs(1);
        for (int i = 2; i <= n && !flag; i++)
        {
            flag = leaf[i] && (++cnt[fa[i]] > 1);
        }
        flag += ((n % 2) || (!(n % 2) && k < (n / 2 - 1)));
        if (flag)
            cout << "Alice" << endl;
        else
            cout << "Bob" << endl;
    }
    return 0;
}