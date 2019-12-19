#include <iostream>
#include <cstdio>

using namespace std;

long long arr[1000007];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        long long ans = 0;
        for (int i = n; i >= 1; i--)
        {
            if (arr[i] >= 0)
            {
                ans++;
            }
            else if (arr[i] < 0)
            {
                long long tmp = arr[i];
                while (tmp < 0 && i >= 1)
                {
                    i--;
                    tmp += arr[i];
                }
                ans++;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}