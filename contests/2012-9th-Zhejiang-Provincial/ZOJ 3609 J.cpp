#include <iostream>
using namespace std;

long long extend_gcd(long long a, long long b, long long &x, long long &y)
{
    if (a == 0 && b == 0)
        return -1;
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extend_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long mod_reverse(long long a, long long n)
{
    long long x, y;
    long long d = extend_gcd(a, n, x, y);
    if (d == 1)
        return (x % n + n) % n;
    else
        return -1;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b;
        cin >> a >> b;
        long long ans = mod_reverse(a, b);
        if (ans == -1)
        {
            cout << "Not Exist" << endl;
        }
        else
        {
            while (ans <= 0)
            {
                ans += b;
            }
            cout << ans << endl;
        }
    }
}