#include <iostream>
#include <map>
using namespace std;

int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    while (n--)
    {
        int k;
        cin >> k;
        mp[k]++;
    }
    int max = 0;
    for (auto m : mp)
    {
        if (m.second > max)
        {
            max = m.second;
        }
    }
    cout << max << endl;
    return 0;
}