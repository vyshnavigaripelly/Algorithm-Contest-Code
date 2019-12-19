#include <iostream>
using namespace std;

const int mod = 1e9 + 7;

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
    return s;
}

int main()
{
    // k=0, 3 = x
    // k=1, 5 6 = ((2x + 2x-1) * 2 / 2) / 2 * 2
    // k=2, 9 10 11 12 = ((4x + 4x-3) * 4 / 2) / 4 * 2
    // k=3, 17 18 ... 24 = ((8x + 8x-7) * 8 / 2) / 8 * 2
    // ((2^k * x + 2^k * x - 2^k + 1) * 2^k / 2) / 2^k * 2
    // 2^k * (2x - 1) + 1
    long long x, k;
    cin >> x >> k;
    if (x == 0)
    {
        cout << 0 << endl;
    }
    else
    {
        cout << ((FastPow(2, k, mod) * ((2 * (x % mod) % mod - 1 + mod) % mod)) % mod + 1) % mod << endl;
    }
    return 0;
}
