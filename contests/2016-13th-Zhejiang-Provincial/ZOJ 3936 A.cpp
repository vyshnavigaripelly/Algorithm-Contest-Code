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
        cout << c << ' ' << b + d << endl
             << a << ' ' << b + d << endl;
    }
    return 0;
}