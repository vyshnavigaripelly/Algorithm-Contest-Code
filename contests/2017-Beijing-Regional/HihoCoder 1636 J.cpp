#include <bits/stdc++.h>

using namespace std;

long long f[107][107][107], sum[107], a[107];

int main()
{
    int n, L, R;
    while (~scanf("%d%d%d", &n, &L, &R))
    {
        for (int i = 1; i <= n; i++)
            scanf("%lld", &a[i]);
        memset(f, 0x3f, sizeof(f));
        memset(sum, 0, sizeof(sum));
        for (int i = 1; i <= n; i++)
        {
            f[i][i][1] = 0;
            sum[i] = sum[i - 1] + a[i];
        }
        for (int len = 1; len < n; len++)
        {
            for (int l = 1; l <= n - len; l++)
            {
                int r = l + len;
                int pos = min(len + 1, r);
                for (int p = 2; p <= pos; p++)
                    for (int k = l + p - 2; k < r; k++)
                        f[l][r][p] = min(f[l][k][p - 1] + f[k + 1][r][1], f[l][r][p]);

                for (int p = L - 1; p <= R - 1; p++)
                    for (int k = l + p - 1; k < r; k++)
                        f[l][r][1] = min(f[l][k][p] + f[k + 1][r][1] + sum[r] - sum[l - 1], f[l][r][1]);
            }
        }
        if (f[1][n][1] == 0x3f3f3f3f3f3f3f3f)
            puts("0");
        else
            printf("%lld\n", f[1][n][1]);
    }
    return 0;
}