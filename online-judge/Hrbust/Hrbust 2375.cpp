#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;

long long FastPow(long long x, long long n, long long mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}

int main()
{
    // 2^(n-3)*n^2*(n+3)
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
        }
        else if (n == 2)
        {
            cout << 10 << endl;
        }
        else
        {
            cout << FastPow(2, n - 3, mod) * n % mod * n % mod * (n + 3) % mod << endl;
        }
    }
    return 0;
}