#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, m, k;
        scanf("%lld %lld %lld", &n, &m, &k);
        if (n == k)
        {
            printf("%lld\n", (m + 1) * k);
            continue;
        }
        long long aa = m / (n - k + 1);
        long long bb = aa + 1;
        long long d = m % (n - k + 1);
        long long d2 = (k - 1) * bb;
        long long d3 = (d + 1) * bb;
        long long d4 = ((n - k + 1) - d - 1) * aa;
        long long dd = d2 + d3 + d4;
        long long b = k * (m + 1);
        printf("%lld\n", min(dd, b));
    }
    return 0;
}