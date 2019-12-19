#include <iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

map<string, int> mp;

int main()
{
    int n;
    while (cin >> n && n)
    {
        mp.clear();
        int maxn = 0;
        string k, ans;
        while (n--)
        {
            cin >> k;
            mp[k]++;
        }
        for (auto i : mp)
        {
            if (i.second > maxn)
            {
                maxn = i.second;
                ans = i.first;
            }
        }
        cout << ans << endl;
    }
    return 0;
}