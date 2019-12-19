#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        mp[k]++;
    }
    int ans = 0;
    for (auto m : mp)
    {
        ans = max(ans, m.second);
    }
    cout << n - ans << endl;
    return 0;
}