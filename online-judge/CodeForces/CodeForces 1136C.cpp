#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> aa[1007], bb[1007];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, m, k;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> k;
            aa[i + j].push_back(k);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> k;
            bb[i + j].push_back(k);
        }
    }
    int flag = 1;
    for (int i = 0; i <= n + m - 2; i++)
    {
        sort(aa[i].begin(), aa[i].end());
        sort(bb[i].begin(), bb[i].end());
        if (aa[i] != bb[i])
        {
            flag = 0;
        }
    }
    cout << (flag ? "YES" : "NO") << endl;
    return 0;
}