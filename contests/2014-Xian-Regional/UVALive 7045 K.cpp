#include <iostream>
using namespace std;

long long sum;

void gcd(long long x, long long y)
{
    if (!y)
        return;
    sum += (x / y);
    gcd(y, x % y);
}

int main()
{
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        long long x, y;
        cin >> x >> y;
        cout << "Case #" << cas << ": ";
        if (!x && !y)
        {
            cout << 1 << endl;
        }
        else if (!x || !y)
        {
            cout << 2 << endl;
        }
        else
        {
            sum = 0;
            gcd(x, y);
            cout << sum + 1 << endl;
        }
    }
    return 0;
}