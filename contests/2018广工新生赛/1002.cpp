#include <iostream>

using namespace std;

long long sum[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }
        while (m--)
        {
            int k, l, r;
            scanf("%d %d %d", &k, &l, &r);
            if (k == 2)
            {
                printf("%lld\n", sum[r] - sum[l - 1]);
            }
        }
    }
    return 0;
}