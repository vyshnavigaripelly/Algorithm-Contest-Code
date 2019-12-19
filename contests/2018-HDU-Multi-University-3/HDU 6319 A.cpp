#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAXN = 1e7 + 7;

long long arr[MAXN];
long long qu[MAXN];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, m, k, p, q, r, mod, A = 0, B = 0;
        scanf("%lld %lld %lld %lld %lld %lld %lld", &n, &m, &k, &p, &q, &r, &mod);
        for (int i = 1; i <= k; i++)
        {
            scanf("%lld", &arr[i]);
        }
        for (int i = k + 1; i <= n; i++)
        {
            arr[i] = (p * arr[i - 1] + q * i + r) % mod;
        }
        int head = 1, tail = 0;
        for (int i = n; i >= 1; i--)
        {
            while (head <= tail && arr[qu[tail]] <= arr[i])
            {
                tail--;
            }
            qu[++tail] = i;
            if (i <= n - m + 1)
            {
                while (head <= tail && qu[head] >= i + m)
                {
                    head++;
                }
                A += (arr[qu[head]] ^ i);
                B += ((tail - head + 1) ^ i);
            }
        }
        printf("%lld %lld\n", A, B);
    }
    return 0;
}