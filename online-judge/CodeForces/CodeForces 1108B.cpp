#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mp;

int flag[20007];
int arr[20007];

int main()
{
    int n;
    cin >> n;
    int maxn = -1, ans = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        maxn = max(maxn, arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        if (maxn % arr[i] == 0 && mp[arr[i]] == 0)
        {
            mp[arr[i]] = 1;
            flag[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            ans = max(ans, arr[i]);
        }
    }
    cout << ans << ' ' << maxn << endl;
    return 0;
}