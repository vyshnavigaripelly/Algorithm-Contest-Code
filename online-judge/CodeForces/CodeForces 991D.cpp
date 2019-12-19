#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s[2];
    int m;
    for (int i = 0; i < 2; i++)
    {
        cin >> s[i];
        m = s[i].length();
    }
    int ans = 0, prev = 0;
    for (int i = 0; i < m; i++)
    {
        int current = (s[0][i] == '0') + (s[1][i] == '0');
        prev += current;
        if (prev >= 3)
        {
            prev -= 3;
            ans++;
        }
        else
        {
            prev = current;
        }
    }
    cout << ans << endl;
}