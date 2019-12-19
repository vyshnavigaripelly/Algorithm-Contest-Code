#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

vector<int> aa[30], bb[30], qa, qb;
vector<pair<int, int>> ans;

int main()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < n; i++)
    {
        if (a[i] == '?')
        {
            qa.push_back(i + 1);
        }
        else
        {
            aa[a[i] - 'a'].push_back(i + 1);
        }
        if (b[i] == '?')
        {
            qb.push_back(i + 1);
        }
        else
        {
            bb[b[i] - 'a'].push_back(i + 1);
        }
    }
    for (int i = 0; i < 26; i++)
    {
        int tmp = min(aa[i].size(), bb[i].size());
        int j;
        for (j = 0; j < tmp; j++)
        {
            ans.push_back({aa[i][j], bb[i][j]});
        }
        j = tmp;
        while (qa.size() > 0 && j < bb[i].size())
        {
            ans.push_back({qa.back(), bb[i][j]});
            qa.pop_back();
            j++;
        }
        j = tmp;
        while (qb.size() > 0 && j < aa[i].size())
        {
            ans.push_back({aa[i][j], qb.back()});
            qb.pop_back();
            j++;
        }
    }
    while (qa.size() > 0 && qb.size() > 0)
    {
        ans.push_back({qa.back(), qb.back()});
        qa.pop_back();
        qb.pop_back();
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i.first << ' ' << i.second << endl;
    }
    return 0;
}