#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        map<char, int> mp;
        string s;
        cin >> s;
        for (int i = 0, len = s.length(); i < len; i++)
        {
            mp[s[i]]++;
        }
        char maxc = 'a';
        int maxn = 0;
        for (auto k : mp)
        {
            if (k.second > maxn)
            {
                maxc = k.first;
                maxn = k.second;
            }
        }
        cout << maxc << ' ' << maxn << endl;
    }
    return 0;
}
