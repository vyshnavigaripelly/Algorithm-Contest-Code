#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '0')
        {
            cnt1++;
            cout << 1 << ' ' << cnt1 << endl;
            cnt1 %= 4;
        }
        else
        {
            cnt2++;
            cout << 4 << ' ' << cnt2 * 2 - 1 << endl;
            cnt2 %= 2;
        }
    }
    return 0;
}