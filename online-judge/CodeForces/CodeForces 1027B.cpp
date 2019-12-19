#include <iostream>
using namespace std;

int main()
{
    long long n, q;
    scanf("%lld %lld", &n, &q);
    while (q--)
    {
        long long x, y;
        scanf("%lld %lld", &x, &y);
        long long ans;
        if ((x % 2 == 1 && y % 2 == 0) || (x % 2 == 0 && y % 2 == 1))
        {
            ans = ((x - 1) * n + y - 1) / 2 + 1 + (n * n + 1) / 2;
        }
        else
        {
            ans = ((x - 1) * n + y - 1) / 2 + 1;
        }
        printf("%lld\n", ans);
    }
    return 0;
}