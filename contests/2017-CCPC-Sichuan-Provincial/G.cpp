#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long a, b, c, d;
    while (~scanf("%lld%lld%lld%lld", &a, &b, &c, &d))
    {
        long long l = b / 2017 - a / 2017;
        if (a % 2017 == 0)
            l++;
        long long r = d / 2017 - c / 2017;
        if (c % 2017 == 0)
            r++;
        long long ans = 1LL * (l * (d - c + 1)) + 1LL * (r * (b - a + 1)) - 1LL * l * r;
        printf("%lld\n", ans);
    }
    return 0;
}