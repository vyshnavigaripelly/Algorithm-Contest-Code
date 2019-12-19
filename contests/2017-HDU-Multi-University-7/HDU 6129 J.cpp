#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int P = 2;

int t, n, m, i, f[P], r[P];

int C(int n, int m)
{
    return n < m ? 0 : f[n] * r[n - m] % P * r[m] % P;
}

int lucas(int n, int m)
{
    if (n < m)
        return 0;
    if (!m || n == m)
        return 1;

    return C(n % P, m % P) * lucas(n / P, m / P) % P;
}

int arr[200007], lu[200007], ans[200007];

int main()
{
    r[0] = r[1] = f[0] = f[1] = 1;
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int tot = 1;
        for (int i = 0; i < n; i++)
        {
            int tmp = lucas(m + i - 1, i);
            if (tmp % 2 == 1)
            {
                lu[tot] = i;
                tot++;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j < tot; j++)
            {
                if (i + lu[j] > n)
                {
                    break;
                }
                ans[i + lu[j]] ^= arr[i];
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d%c", ans[i], i == n ? '\n' : ' ');
        }
    }
    return 0;
}