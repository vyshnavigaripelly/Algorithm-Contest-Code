#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int N = 2e5 + 7;

map<int, int> mp;
int arr[N], flag;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        mp[arr[i]]++;
        if (mp[arr[i]] >= 3)
        {
            flag = 1;
        }
    }
    if (flag)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        int sum = 0;
        cout << mp.size() << endl;
        for (auto i : mp)
        {
            cout << i.first << ' ';
            if (i.second == 2)
            {
                sum++;
            }
        }
        cout << endl;
        cout << sum << endl;
        for (auto i = mp.rbegin(); i != mp.rend(); i++)
        {
            if (i->second == 2)
            {
                cout << i->first << ' ';
            }
        }
    }
    return 0;
}