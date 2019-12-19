#include <iostream>

using namespace std;

const int mod = 1e6 + 3;

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        long long ans = 1;
        if (n >= mod)
        {
            ans = 0;
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                ans *= i;
                ans %= mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}