#include <iostream>
#include <map>
#include <vector>
using namespace std;

int main()
{
    int n, k, arr[150];
    vector<int> ans;
    cin >> n >> k;
    map<int, int> mp;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (mp[arr[i]] == 0)
        {
            mp[arr[i]]++;
            ans.push_back(i);
        }
    }
    if (ans.size() >= k)
    {
        cout << "YES" << endl;
        for (int i = 0; i < k; i++)
        {
            cout << ans[i] << ' ';
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}
