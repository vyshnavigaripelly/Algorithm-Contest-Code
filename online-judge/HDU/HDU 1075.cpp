#include <iostream>
#include <string>
#include <cstdio>
#include <map>

using namespace std;

map<string, string> mp;

int main()
{
    string s;
    cin >> s;
    string a, b;
    while (cin >> a && a != "END")
    {
        cin >> b;
        mp[b] = a;
    }
    cin >> s;
    getchar();
    while (getline(cin, s) && s != "END")
    {
        int len = s.length();
        for (int i = 0; i < len; i++)
        {
            int j = i;
            while (j < len && (isalpha(s[i]) == isalpha(s[j])))
            {
                j++;
            }
            string tmp = s.substr(i, j - i);
            if (mp.count(tmp))
            {
                cout << mp[tmp];
            }
            else
            {
                cout << tmp;
            }
            i = j - 1;
        }
        cout << endl;
    }
    return 0;
}