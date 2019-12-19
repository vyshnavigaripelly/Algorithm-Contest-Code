#include <iostream>
#include <map>
#include <cctype>

using namespace std;

map<string, int> mp;
map<char, char> mp2;

int main()
{
    string a = "ABCDEFGHIJKLMNOPRSTUVWXY";
    string b = "222333444555666777888999";
    for (int i = 0; i < a.length(); i++)
    {
        mp2[a[i]] = b[i];
    }
    int n;
    while (cin >> n)
    {
        mp.clear();
        while (n--)
        {
            string s, tmp;
            cin >> s;
            for (int i = 0; i < s.length(); i++)
            {
                if (s[i] == '-')
                {
                    continue;
                }
                else if (isalpha(s[i]))
                {
                    tmp += mp2[s[i]];
                }
                else if (isdigit(s[i]))
                {
                    tmp += s[i];
                }
            }
            mp[tmp]++;
        }
        int flag = 1;
        for (auto i : mp)
        {
            if (i.second > 1)
            {
                flag = 0;
                cout << i.first.substr(0, 3) << '-' << i.first.substr(3) << ' ' << i.second << endl;
            }
        }
        if (flag)
        {
            cout << "No duplicates." << endl;
        }
    }
    return 0;
}