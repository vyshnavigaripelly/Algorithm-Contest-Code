#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s, t;
    cin >> s >> t;
    int ans = 0, len1 = s.length(), len2 = t.length();
    for (int i = len1 - 1, j = len2 - 1; i >= 0 && j >= 0; i--, j--)
    {
        if (s[i] != t[j])
        {
            break;
        }
        ans++;
    }
    cout << len1 + len2 - 2 * ans << endl;
    return 0;
}