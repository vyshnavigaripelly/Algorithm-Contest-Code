#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n, p;
    string s;
    cin >> n >> p >> s;
    int flag = 1;
    for (int i = 0; i < n - p; i++)
    {
        if ((s[i] == '0' && s[i + p] == '1') || (s[i] == '1' && s[i + p] == '0'))
        {
            flag = 0;
        }
        if (s[i] == '.')
        {
            flag = 0;
            if (s[i + p] == '0')
            {
                s[i] = '1';
            }
            else if (s[i + p] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '0';
                s[i + p] = '1';
            }
        }
        else if (s[i + p] == '.')
        {
            flag = 0;
            if (s[i] == '0')
            {
                s[i + p] = '1';
            }
            else if (s[i] == '1')
            {
                s[i + p] = '0';
            }
            else
            {
                s[i] = '0';
                s[i + p] = '1';
            }
        }
    }
    if (flag)
    {
        cout << "No" << endl;
    }
    else
    {
        for (int i = n - p; i < n; i++)
        {
            if (s[i] == '.')
            {
                s[i] = '0';
            }
        }
        cout << s << endl;
    }
    return 0;
}