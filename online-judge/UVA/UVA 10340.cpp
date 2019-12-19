#include <iostream>
using namespace std;

int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        int lens = s.length(), lent = t.length();
        int p = 0;
        for (int i = 0; i < lent; i++)
        {
            if (s[p] == t[i])
            {
                p++;
            }
        }
        if (p == lens)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
