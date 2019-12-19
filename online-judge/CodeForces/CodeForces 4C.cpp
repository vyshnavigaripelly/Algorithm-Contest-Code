#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> mp;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;
        cin >> s;
        if (mp.count(s))
        {
            cout << s << mp[s] << endl;
        }
        else
        {
            cout << "OK" << endl;
        }
        mp[s]++;
    }
    return 0;
}