#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        if (!(a % 2) || !(b % 2) || !(c % 2))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}
