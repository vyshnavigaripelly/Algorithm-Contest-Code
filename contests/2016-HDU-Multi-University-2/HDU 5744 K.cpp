#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        long long odd = 0, even = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            if (tmp & 1)
            {
                odd++;
                tmp--;
            }
            even += tmp;
        }
        if (!odd)
        {
            printf("%lld\n", even);
        }
        else
        {
            printf("%lld\n", (even / (2 * odd)) * 2 + 1);
        }
    }
    return 0;
}