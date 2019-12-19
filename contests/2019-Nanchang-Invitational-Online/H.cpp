#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

long long fpow(long long a, long long b, long long mod = mod)
{
    long long s = 1;
    while (b)
    {
        if (b & 1)
        {
            s = s * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return s;
}

int main()
{
    int n;
    scanf("%d", &n);
    long long ans;
    if (n == 1)
    {
        ans = 1;
    }
    else
    {
        ans = 4 * fpow(3, n - 2) % mod;
    }
    printf("%lld\n", ans);
    return 0;
}