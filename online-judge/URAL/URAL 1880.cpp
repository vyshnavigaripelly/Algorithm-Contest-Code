#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<int, int> rk[4];

int main()
{
    for (int t = 0; t < 3; t++)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            cin >> tmp;
            rk[t][tmp] = 1;
        }
    }
    int ans = 0;
    for (auto i : rk[0])
    {
        if (rk[1].count(i.first) && rk[2].count(i.first))
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}