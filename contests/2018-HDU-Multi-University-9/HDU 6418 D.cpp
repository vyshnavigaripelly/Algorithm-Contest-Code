#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a1, b1, c1, a2, b2, c2;
        scanf("%lld %lld %lld %lld %lld %lld", &a1, &b1, &c1, &a2, &b2, &c2);
        long long fenzi = a2 * c1 - a2 * b1 - b2 * c1 + b2 * a1 + c2 * b1 - c2 * a1;
        long long fenmu = a1 + b1 + c1;
        int flag = 1;
        if (fenzi < 0)
        {
            fenzi = -fenzi;
            flag = -1;
        }
        if (fenzi % fenmu == 0)
            printf("%lld\n", fenzi / fenmu * flag);
        else
        {
            long long GCD = __gcd(fenzi, fenmu);
            fenzi /= GCD;
            fenmu /= GCD;
            printf("%lld/%lld\n", fenzi * flag, fenmu);
        }
    }
    return 0;
}