#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 4e4 + 7;
const int mod = 192600817;

long long arr[N + 4] = {0, 1, 1}, sum[N + 4] = {0, 1, 2};

int main()
{
    for (int i = 3; i <= N; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 2]) % mod;
        sum[i] = (sum[i - 1] + arr[i] * arr[i]) % mod;
    }
    int q;
    while (~scanf("%d", &q))
    {
        while (q--)
        {
            int a, b, c, d;
            scanf("%d %d %d %d", &a, &b, &c, &d);
            int x = a * 4 + b, y = c * 4 + d;
            x++, y++;
            if (x > y)
            {
                swap(x, y);
            }
            long long ans = (sum[y] - sum[x - 1] + mod) % mod;
            printf("%lld\n", ans);
        }
    }
    return 0;
}