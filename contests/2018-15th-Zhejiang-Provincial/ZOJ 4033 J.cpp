#include <iostream>
#include <string>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s, ans;
        cin >> n >> s;
        int len = s.length();
        if (len % 4 == 0 || (len - 3) % 4 == 0)
        {
            if ((len - 3) % 4 == 0)
            {
                if (s[0] == '0')
                    ans += "1";
                if (s[0] == '1')
                    ans += "3";
                if (s[1] == '0')
                    ans += "1";
                if (s[1] == '1')
                    ans += "3";
                if (s[2] == '0')
                    ans += "2";
                if (s[2] == '1')
                    ans += "4";
                for (int i = 3; i < len; i++)
                {
                    if (i % 4 == 3)
                    {
                        if (s[i] == '0')
                            ans += "1";
                        else
                            ans += "3";
                    }
                    else if (i % 4 == 0)
                    {
                        if (s[i] == '0')
                            ans += "2";
                        else
                            ans += "4";
                    }
                    else if (i % 4 == 1)
                    {
                        if (s[i] == '0')
                            ans += "2";
                        else
                            ans += "4";
                    }
                    else
                    {
                        if (s[i] == '0')
                            ans += "1";
                        else
                            ans += "3";
                    }
                }
                cout << ans << endl;
            }
            else
            {
                for (int i = 0; i < len; i++)
                {
                    if (i % 4 == 0)
                    {
                        if (s[i] == '0')
                            ans += "1";
                        else
                            ans += "3";
                    }
                    else if (i % 4 == 1)
                    {
                        if (s[i] == '0')
                            ans += "2";
                        else
                            ans += "4";
                    }
                    else if (i % 4 == 2)
                    {
                        if (s[i] == '0')
                            ans += "2";
                        else
                            ans += "4";
                    }
                    else
                    {
                        if (s[i] == '0')
                            ans += "1";
                        else
                            ans += "3";
                    }
                }
                cout << ans << endl;
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
