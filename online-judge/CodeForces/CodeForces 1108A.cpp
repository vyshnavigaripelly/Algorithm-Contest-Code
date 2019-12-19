#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a == c && b == d)
        {
            cout << a << ' ' << b << endl;
        }
        else if (a == c)
        {
            cout << b << ' ' << d << endl;
        }
        else if (b == d)
        {
            cout << a << ' ' << c << endl;
        }
        else if (a == d)
        {
            cout << b << ' ' << c << endl;
        }
        else
        {
            cout << a << ' ' << d << endl;
        }
    }
    return 0;
}