#include <iostream>
#include <map>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        map<string, map<string, int>> mp;
        while (m--)
        {
            string a, b;
            int k;
            cin >> a >> b >> k;
            mp[b][a] += k;
        }
        for (auto i : mp)
        {
            cout << i.first << endl;
            for (auto j : i.second)
            {
                cout << "   |----" << j.first << "(" << j.second << ")" << endl;
            }
        }
        if (n > 0)
        {
            cout << endl;
        }
    }
    return 0;
}