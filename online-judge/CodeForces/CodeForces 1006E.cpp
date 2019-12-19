#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

const int maxn = 1e6 + 7;
int n;
vector<int> gra[maxn];
pair<int, int> pa[maxn];
int cnt, ans[maxn];

void dfs(int v)
{
    pa[v].first = cnt;
    ans[cnt++] = v;
    for (int i = 0; i < gra[v].size(); i++)
    {
        dfs(gra[v][i]);
    }
    pa[v].second = cnt;
}

int main()
{
    int m;
    cin >> n >> m;
    for (int i = 2; i <= n; i++)
    {
        int k;
        cin >> k;
        gra[k].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        sort(gra[i].begin(), gra[i].end());
    }
    dfs(1);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int t = pa[a].first + b - 1;
        if (t < pa[a].second)
        {
            cout << ans[t] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}