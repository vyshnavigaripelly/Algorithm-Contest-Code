#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long a, b;
    while (cin >> a >> b)
    {
        long long k = __gcd(a, b);
        long long delta = a * a - 4 * k * b;
        if (delta < 0)
        {
            cout << "No Solution" << endl;
            continue;
        }
        long long x1 = (a + sqrt(delta)) / 2 / k;
        long long x2 = (a - sqrt(delta)) / 2 / k;
        if (k * (x1 + x2) == a)
        {
            cout << x2 * k << ' ' << x1 * k << endl;
        }
        else
        {
            cout << "No Solution" << endl;
        }
    }
    return 0;
}