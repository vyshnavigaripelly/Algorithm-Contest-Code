#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    int n, k;
    string s;
    cin >> n >> k >> s;
    sort(s.begin(), s.end());
    int ans = 0, last = 0, cnt = 0, flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] - last >= 2)
        {
            ans += s[i] - 'a' + 1;
            last = s[i];
            cnt++;
        }
        if (cnt == k)
        {
            flag = 1;
            break;
        }
    }
    if (flag)
    {
        cout << ans << endl;
    }
    else
    {
        cout << -1 << endl;
    }
    return 0;
}