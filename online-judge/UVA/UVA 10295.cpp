#include <iostream>
#include <map>
#include <string>

using namespace std;

map<string, int> mp;

int main()
{
    int n, m;
    cin >> n >> m;
    while (n--)
    {
        string s;
        int k;
        cin >> s >> k;
        mp[s] = k;
    }
    while (m--)
    {
        long long ans = 0;
        string s;
        while (cin >> s && s != ".")
        {
            ans += mp[s];
        }
        cout << ans << endl;
    }
    return 0;
}