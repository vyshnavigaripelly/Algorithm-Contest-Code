#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, x, y;
    string s;
    cin >> n >> x >> y >> s;
    int groups = 0, flag = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0' && flag)
        {
            flag = 0;
            groups++;
        }
        if (s[i] == '1')
        {
            flag = 1;
        }
    }
    if (groups == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        long long ans = 1LL * (groups - 1) * (x < y ? x : y) + y;
        cout << ans << endl;
    }
    return 0;
}