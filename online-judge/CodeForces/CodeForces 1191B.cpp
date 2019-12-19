#include <iostream>
#include <algorithm>

using namespace std;

string s[3];

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> s[i];
    }
    sort(s, s + 3);
    if (s[0] == s[1] && s[1] == s[2] ||
        ((s[0][1] == s[1][1] && s[1][1] == s[2][1]) && (s[2][0] - s[1][0] == 1) && (s[1][0] - s[0][0] == 1)))
    {
        cout << 0 << endl;
    }
    else if (s[0] == s[1] || s[1] == s[2] ||
             (s[0][1] == s[1][1] && ((s[1][0] - s[0][0] == 1) || (s[1][0] - s[0][0] == 2))) ||
             (s[1][1] == s[2][1] && ((s[2][0] - s[1][0] == 1) || (s[2][0] - s[1][0] == 2))) ||
             (s[0][1] == s[2][1] && ((s[2][0] - s[0][0] == 1) || (s[2][0] - s[0][0] == 2))))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 2 << endl;
    }
    return 0;
}