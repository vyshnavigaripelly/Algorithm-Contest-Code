#include <iostream>
#include <map>
#include <vector>

using namespace std;

map<int, int> mp;

int arr[100007], ans[100007];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        mp[arr[i]]++;
        if (mp.size() == n)
        {
            ans[i] = 1;
            vector<int> tmp;
            for (auto &i : mp)
            {
                i.second--;
                if (i.second == 0)
                {
                    tmp.push_back(i.first);
                }
            }
            for (auto i : tmp)
            {
                mp.erase(i);
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        cout << ans[i];
    }
    return 0;
}