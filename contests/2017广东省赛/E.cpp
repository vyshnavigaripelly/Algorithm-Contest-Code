#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long s, w, x, y, vmax, b;
        scanf("%lld %lld %lld %lld %lld %lld", &s, &w, &x, &y, &vmax, &b);
        long long ans = sqrt(b);
        long long sum = 0x3f3f3f3f3f3f3f3f;
        if (b % w == 0)
        {
            long long tt = b / w;
            sum = tt * s;
        }
        else
        {
            long long tt = b / w + 1;
            sum = tt * s;
        }
        for (int i = ans + 2; i > 0; i--)
        {

            long long ss = b / i;
            if (b % i != 0)
                ss++;
            if (ss < w)
            {
                continue;
            }
            ss -= w;
            long long ll;
            if (ss % y == 0)
            {
                ll = ss / y;
            }
            else
            {
                ll = ss / y + 1;
            }
            if (ll > vmax)
                continue;
            sum = min(i * (s + ll * x), sum);
        }
        for (int i = 1; i <= vmax; i++)
        {
            long long ss = i * y + w;
            if (ss > ans + 2)
                break;
            long long t;
            t = b / ss;
            if (b % ss != 0)
                t++;
            sum = min(t * (s + i * x), sum);
        }
        printf("%lld\n", sum);
    }
    return 0;
}
