#include <iostream>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>

using namespace std;

map<string, vector<string>> mp;

int main()
{
    string s;
    while (cin >> s && s != "#")
    {
        string t = s;
        for (auto &c : t)
        {
            c = tolower(c);
        }
        sort(t.begin(), t.end());
        mp[t].push_back(s);
    }
    vector<string> ans;
    for (auto i : mp)
    {
        if (i.second.size() == 1)
        {
            ans.push_back(i.second[0]);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
    {
        cout << i << endl;
    }
    return 0;
}