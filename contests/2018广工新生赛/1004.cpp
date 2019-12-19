#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ans = 0;
        string s;
        cin >> n;
        while (n--)
        {
            cin >> s;
            if (s == "int")
            {
                ans += 4;
            }
            else if (s == "bool")
            {
                ans += 1;
            }
            else if (s == "long")
            {
                cin >> s;
                ans += 8;
            }
            else if (s == "double")
            {
                ans += 8;
            }
            else if (s == "char")
            {
                ans += 1;
            }
            else if (s == "float")
            {
                ans += 4;
            }
            cin >> s;
        }
        cout << (ans + 1023) / 1024 << endl;
    }
    return 0;
}