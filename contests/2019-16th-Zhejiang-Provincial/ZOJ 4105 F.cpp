#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        cout << s[0];
        for (int i = 1; i < s.length(); i++)
        {
            if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' ||
                s[i] == 'y' || s[i] == 'o' || s[i] == 'u')
            {
                continue;
            }
            cout << s[i];
        }
        cout << endl;
    }
    return 0;
}