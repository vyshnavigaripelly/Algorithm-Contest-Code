#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long x1, y1, x2, y2, x3, y3;
    while (~scanf("%lld %lld %lld %lld %lld %lld", &x1, &y1, &x2, &y2, &x3, &y3))
    {
        long long ans = x1 * y2 - y1 * x2 + x2 * y3 - y2 * x3 + x3 * y1 - y3 * x1;
        printf("%lld\n", 11 * abs(ans));
    }
    return 0;
}