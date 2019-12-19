#include <iostream>

using namespace std;

long long ans[] = {1, 9, 41, 109, 205};

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        long long n;
        scanf("%lld", &n);
        if (n < 5)
            printf("Case #%d: %lld\n", cas, ans[n]);
        else
        {
            unsigned long long tmp = n, ans = 14 * tmp * tmp - 6 * tmp + 5;
            printf("Case #%d: %llu\n", cas, ans);
        }
    }
    return 0;
}