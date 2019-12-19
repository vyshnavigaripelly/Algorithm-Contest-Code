#include <iostream>
#include <vector>
#include <bitset>

using namespace std;

int main()
{
    int x;
    cin >> x;
    vector<int> ans;
    int cnt = 0;
    while ((x & (x + 1)) != 0)
    {
        int n = __builtin_ctz(x);
        ans.push_back(n);
        x ^= ((1 << n) - 1);
        cnt++;
        if ((x & (x + 1)) != 0)
        {
            x++;
            cnt++;
        }
    }
    cout << cnt << endl;
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}