#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
    long long n, k;
    for (int cas = 1; ~scanf("%lld %lld", &n, &k); cas++)
    {
        printf("Case #%d: ", cas);
        if (n == 2)
        {
            printf("%lld\n", ((k % 2) ^ 1) + 1);
        }
        else
        {
            if (k <= n - 1)
            {
                printf("%lld\n", k);
            }
            else
            {
                k -= n - 1;
                long long m = k % (2 * (n - 1));
                if (m == 1)
                {
                    printf("%lld\n", n);
                }
                else if (m == 0)
                {
                    printf("%lld\n", n - 2);
                }
                else if (m >= 2 && m <= n)
                {
                    printf("%lld\n", m - 1);
                }
                else
                {
                    printf("%lld\n", m - n);
                }
            }
        }
    }
    return 0;
}