#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long m;
    for (int cas = 1; ~scanf("%lld", &m); cas++)
    {
        long long x = m * log10(2.0);
        printf("Case #%d: %lld\n", cas, x);
    }
    return 0;
}