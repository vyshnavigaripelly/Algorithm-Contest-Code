#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long n, m;
    while (~scanf("%lld %lld", &n, &m))
    {
        long long a = __gcd(n, m), b = 2 * m * n;
        long long g = __gcd(a, b);
        printf("%lld/%lld\n", a / g, b / g);
    }
    return 0;
}