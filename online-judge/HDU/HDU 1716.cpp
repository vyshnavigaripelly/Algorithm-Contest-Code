#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    string a, b, c, d;
    int flag = 1;
    while (cin >> a >> b >> c >> d)
    {
        string s = a + b + c + d;
        if (s == "0000")
        {
            break;
        }
        if (!flag)
        {
            cout << endl;
        }
        flag = 1;
        sort(s.begin(), s.end());
        char last = s[0];
        string ans;
        do
        {
            if (s[0] == '0')
            {
                continue;
            }
            if (flag)
            {
                flag = 0;
            }
            else if (s[0] == last)
            {
                cout << ' ';
            }
            else
            {
                cout << endl;
            }
            cout << s;
            last = s[0];
        } while (next_permutation(s.begin(), s.end()));
        cout << endl;
    }
    return 0;
}