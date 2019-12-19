#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

int arr[2007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if (!(n % 3))
        {
            long long x = n / 3;
            printf("%lld\n", x * x * x);
        }
        else if (!(n % 4))
        {
            long long x = n / 2;
            long long y = n / 4;
            printf("%lld\n", x * y * y);
        }
        else
            printf("-1\n");
    }
    return 0;
}