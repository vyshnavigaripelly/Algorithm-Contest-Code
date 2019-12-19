#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    int n;
    while (t--)
    {
        int ans = 0;
        string s;
        cin >> n >> s;
        for (int i = 0; i < n - 3; i++)
        {
            if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P' && s[i + 3] == 'C')
                ans++;
        }
        for (int i = 0; i < n - 2; i++)
        {
            int flag = 0;
            if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'C') // CCCPC
            {
                if (s[i + 3] != 'P')
                    flag = 1;
            }
            if (s[i] == 'C' && s[i + 1] == 'C' && s[i + 2] == 'P') // CCP
            {
                if (s[i + 3] != 'C')
                    flag = 1;
            }
            if (s[i] == 'C' && s[i + 1] == 'P' && s[i + 2] == 'C') // CPC
            {
                if (i == 0 || s[i - 1] != 'C')
                    flag = 1;
            }
            if (flag)
            {
                ans++;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}