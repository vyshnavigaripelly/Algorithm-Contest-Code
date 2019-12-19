#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    if (s[0] > 'a' && s[0] < 'h')
    {
        if (s[1] > '1' && s[1] < '8')
        {
            cout << 8 << endl;
        }
        else
        {
            cout << 5 << endl;
        }
    }
    else
    {
        if (s[1] > '1' && s[1] < '8')
        {
            cout << 5 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }
    return 0;
}