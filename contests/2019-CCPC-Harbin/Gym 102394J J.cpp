#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n;
        scanf("%lld", &n);
        if (n <= 5)
            puts("-1");
        else
        {
            if (n % 2 == 0)
            {
                printf("2 %lld\n", n - 2);
            }
            else
            {
                printf("3 %lld\n", n - 3);
            }
        }
    }
    return 0;
}