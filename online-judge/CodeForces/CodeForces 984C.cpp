#include <iostream>
#include <cstdio>
using namespace std;

long long gcd(long long a, long long b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    long long p, q, b;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%lld %lld %lld", &p, &q, &b);
        if (p == 0)
        {
            printf("Finite\n");
            continue;
        }
        long long ans = gcd(p, q);
        q /= ans;
        ans = gcd(q, b);
        while (q > 1)
        {
            ans = gcd(q, b);
            if (ans == 1)
            {
                break;
            }
            while (q % ans == 0)
            {
                q /= ans;
            }
        }
        if (q == 1)
        {
            printf("Finite\n");
        }
        else
        {
            printf("Infinite\n");
        }
    }
    return 0;
}
