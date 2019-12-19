#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        if (k == 2)
            n *= n;
        printf("%lld\n", (n - 1) % 9 + 1);
    }
    return 0;
}