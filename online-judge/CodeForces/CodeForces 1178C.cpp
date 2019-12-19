#include <iostream>

using namespace std;

const int mod = 998244353;

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
    long long w, h;
    cin >> w >> h;
    cout << qpow(2, w + h) << endl;
    return 0;
}