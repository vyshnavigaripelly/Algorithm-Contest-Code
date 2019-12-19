#include <iostream>
#include <map>

using namespace std;

pair<long long, long long> a[1007], b[1007];
map<pair<long long, long long>, int> mp;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i].first >> b[i].second;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            mp[{a[i].first + b[j].first, a[i].second + b[j].second}]++;
        }
    }
    for (auto i : mp)
    {
        if (i.second >= n)
        {
            cout << i.first.first << ' ' << i.first.second << endl;
            break;
        }
    }
    return 0;
}