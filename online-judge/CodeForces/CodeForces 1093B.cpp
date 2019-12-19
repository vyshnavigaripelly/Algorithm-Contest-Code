#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        string t = s;
        sort(s.begin(), s.end());
        if (s == t && s[0] == s[s.length() - 1])
        {
            cout << -1 << endl;
        }
        else
        {
            cout << s << endl;
        }
    }
    return 0;
}