#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    long long a, b, x, y;
    scanf("%lld %lld %lld %lld", &a, &b, &x, &y);
    long long g = __gcd(x, y);
    x /= g;
    y /= g;
    long long ans = min(a / x, b / y);
    printf("%lld\n", ans);
    return 0;
}