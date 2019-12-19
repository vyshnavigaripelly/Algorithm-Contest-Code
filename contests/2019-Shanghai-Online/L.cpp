#include <iostream>

using namespace std;

const int N = 1e6 + 7;

long long ans[N][12];

int main()
{
    for (int i = 1; i <= 1000000; i++)
    {
        for (int b = 2; b <= 10; b++)
        {
            long long a = 0;
            int tmp = i;
            while (tmp >= b)
            {
                a += (tmp % b);
                tmp = tmp / b;
            }
            a += tmp;
            ans[i][b] = a;
        }
    }
    for (int b = 2; b <= 10; b++)
    {
        for (int i = 1; i <= 1000000; i++)
        {
            ans[i][b] += ans[i - 1][b];
        }
    }
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, b;
        scanf("%d%d", &n, &b);
        printf("Case #%d: %lld\n", cas, ans[n][b]);
    }
    return 0;
}