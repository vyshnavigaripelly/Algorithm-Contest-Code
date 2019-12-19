#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;

long long qpow(long long x, long long n)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s;
}

int main()
{
    int t;
    long long res = 1;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        if (n == 1)
        {
            cout << res << endl;
        }
        else if (m == 0)
        {
            res = 0;
            cout << res << endl;
        }
        else
        {
            res *= qpow(n - 1, mod - 2);
            res %= mod;
            cout << res << endl;
        }
    }
    return 0;
}