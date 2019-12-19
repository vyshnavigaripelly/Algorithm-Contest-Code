#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int num = 0, lower = 0, upper = 0;
        string s;
        cin >> s;
        for (int i = 0; i < s.length(); i++)
        {
            if (islower(s[i]))
            {
                lower++;
            }
            else if (isupper(s[i]))
            {
                upper++;
            }
            else if (isdigit(s[i]))
            {
                num++;
            }
        }
        if (lower && !upper && !num)
        {
            s[0] = 'A', s[1] = '1';
        }
        else if (upper && !lower && !num)
        {
            s[0] = 'a', s[1] = '1';
        }
        else if (num && !upper && !lower)
        {
            s[0] = 'A', s[1] = 'a';
        }
        else if (!lower && upper && num)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if ((upper == 1 && isdigit(s[i])) || (upper != 1 && isupper(s[i])))
                {
                    s[i] = 'a';
                    break;
                }
            }
        }
        else if (!upper && lower && num)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if ((lower == 1 && isdigit(s[i])) || (lower != 1 && islower(s[i])))
                {
                    s[i] = 'A';
                    break;
                }
            }
        }
        else if (!num && upper && lower)
        {
            for (int i = 0; i < s.length(); i++)
            {
                if ((upper == 1 && islower(s[i])) || (upper != 1 && isupper(s[i])))
                {
                    s[i] = '1';
                    break;
                }
            }
        }
        cout << s << endl;
    }
    return 0;
}