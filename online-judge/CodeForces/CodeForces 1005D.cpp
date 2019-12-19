#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;
    int len = s.length(), ans = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < len; i++)
    {
        int tmp = (s[i] - '0') % 3;
        if (tmp == 1)
        {
            cnt1++;
        }
        if (tmp == 2)
        {
            cnt2++;
        }
        if (tmp == 0 || cnt1 == 3 || cnt2 == 3 || (cnt1 && cnt2))
        {
            ans++;
            cnt1 = 0;
            cnt2 = 0;
        }
    }
    cout << ans << endl;
    return 0;
}