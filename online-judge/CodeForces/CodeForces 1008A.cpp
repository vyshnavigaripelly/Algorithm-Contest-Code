#include <iostream>
#include <string>
using namespace std;

int isvowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    string s;
    cin >> s;
    s += "p";
    int flag = 1;
    for (int i = 0; i < s.length() - 1; i++)
    {
        if (s[i] == 'n' || isvowel(s[i]))
        {
            continue;
        }
        else if (!isvowel(s[i]) && isvowel(s[i + 1]))
        {
            continue;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}