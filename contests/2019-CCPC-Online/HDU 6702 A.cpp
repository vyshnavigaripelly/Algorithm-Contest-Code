#include <bits/stdc++.h>

using namespace std;

long long lowbit(long long x)
{
    return x & -x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        if (a & b)
        {
            printf("%lld\n", a & b);
        }
        else
        {
            printf("%lld\n", lowbit(a | b));
        }
    }
    return 0;
}