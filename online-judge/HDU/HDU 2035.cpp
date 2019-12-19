#include <iostream>
using namespace std;

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
    int a, b;
    while (cin >> a >> b && a != 0 && b != 0)
    {
        cout << FastPow(a, b, 1000) << endl;
    }
    return 0;
}
