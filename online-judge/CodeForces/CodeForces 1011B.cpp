#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

int arr[150];

int main()
{
    int n, m;
    cin >> n >> m;
    map<int, int> mp;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
    }
    vector<int> v;
    for (auto k : mp)
    {
        v.push_back(k.second);
    }
    sort(v.begin(), v.end(), greater<int>());
    int ans = 0;
    for (int i = 100; i > 0; i--)
    {
        int tmp = n;
        for (int k : v)
        {
            tmp -= k / i;
        }
        if (tmp <= 0)
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}