#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        long long a, b, c, d, p, m;
        scanf("%lld %lld %lld %lld %lld %lld", &a, &b, &c, &d, &p, &m);
        if (b - a + 1 < d - c + 1)
        {
            swap(a, c);
            swap(b, d);
        }

        unsigned long long left = 0;
        long long kl1 = ceil(1.0 * (a + c - m) / p),
                  kl2 = floor(1.0 * (a + d - m) / p);
        if (kl1 <= kl2)
        {
            long long sl = (kl1 * p + m - a) - c + 1,
                      nl = kl2 - kl1 + 1;
            left = (sl + (sl + p * (nl - 1))) * nl / 2;
        }

        unsigned long long right = 0;
        long long kr1 = ceil(1.0 * (b + c - m) / p),
                  kr2 = floor(1.0 * (b + d - m) / p);
        if (kr1 <= kr2)
        {
            long long sr = d - (kr2 * p + m - b) + 1,
                      nr = kr2 - kr1 + 1;
            right = (sr + (sr + p * (nr - 1))) * nr / 2;
        }

        unsigned long long middle = 0;
        if (d - c + 1 != b - a + 1)
        {
            long long km1 = ceil(1.0 * ((a + 1) + d - m) / p),
                      km2 = floor(1.0 * ((b - 1) + c - m) / p);
            if (km1 <= km2)
            {
                long long nm = km2 - km1 + 1;
                middle = nm * (d - c + 1);
            }
        }

        if ((a + d) % p == m && d - c + 1 == b - a + 1)
        {
            left -= d - c + 1;
        }

        long long P = left + middle + right, Q = (b - a + 1) * (d - c + 1);
        long long g = __gcd(P, Q);
        printf("Case #%d: %lld/%lld\n", cas, P / g, Q / g);
    }
    return 0;
}