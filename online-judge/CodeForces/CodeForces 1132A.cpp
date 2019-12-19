#include <iostream>

using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if ((!a && !b && c && !d) || (!a && !d && b && c))
    {
        cout << 0 << endl;
    }
    else if (a == d)
    {
        cout << 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}