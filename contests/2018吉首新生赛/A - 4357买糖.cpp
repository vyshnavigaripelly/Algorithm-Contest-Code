#include <iostream>
using namespace std;

int main()
{
    int a, b, p;
    while (cin >> a >> b >> p)
    {
        cout << a + (b - a) * (p - 1) << endl;
    }
    return 0;
}
