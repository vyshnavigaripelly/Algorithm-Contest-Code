#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.length() == 2 && s[0] >= s[1])
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl
                 << 2 << endl
                 << s[0] << ' ' << s.substr(1) << endl;
        }
    }
    return 0;
}