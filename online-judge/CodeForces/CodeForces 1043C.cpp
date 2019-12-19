#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int flag[1007];

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] != s[i + 1])
        {
            reverse(s.begin(), s.begin() + i + 1);
            flag[i] = 1;
        }
        // cout << s << endl;
    }
    if (s[0] == 'b')
    {
        reverse(s.begin(), s.end());
        flag[n - 1] = 1;
    }
    // cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        cout << flag[i] << ' ';
    }
    return 0;
}