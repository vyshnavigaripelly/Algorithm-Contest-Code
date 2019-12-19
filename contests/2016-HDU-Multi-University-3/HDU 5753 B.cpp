#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long long c[1007];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &c[i]);
        }
        if (n == 1)
        {
            printf("%.6f\n", 1.0 * c[1]);
        }
        else if (n == 2)
        {
            printf("%.6f\n", (c[1] + c[2]) / 2.0);
        }
        else
        {
            printf("%.6f\n", (c[1] + c[n]) / 2.0 + accumulate(c + 2, c + n, 0LL) / 3.0);
        }
    }
    return 0;
}