#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, string> mp;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        string s;
        cin >> a >> b >> s;
        mp[{a, b}] = s;
    }
    int q;
    cin >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        cout << mp[{a, b}] << endl;
    }
    return 0;
}