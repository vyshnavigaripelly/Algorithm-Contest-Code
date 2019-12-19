#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string s;
    cin >> s;
    int flag1 = -1, flag2 = -1, flag3 = -1, flag4 = -1;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '[')
        {
            flag1 = i;
            break;
        }
    }
    if (flag1 == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = flag1; i < s.length(); i++)
    {
        if (s[i] == ':')
        {
            flag2 = i;
            break;
        }
    }
    if (flag2 == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = s.length() - 1; i > flag2; i--)
    {
        if (s[i] == ']')
        {
            flag4 = i;
            break;
        }
    }
    if (flag4 == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    for (int i = flag4 - 1; i > flag2; i--)
    {
        if (s[i] == ':')
        {
            flag3 = i;
            break;
        }
    }
    if (flag3 == -1)
    {
        cout << -1 << endl;
        return 0;
    }
    int ans = 4;
    for (int i = flag2 + 1; i < flag3; i++)
    {
        if (s[i] == '|')
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}