#include <bits/stdc++.h>

using namespace std;

const int N = 1e4 + 7;

int n, m;
double dp[N][127];
double brr[127][127];
int val[N];
int arr[11] = {0, 0, 0, 1, 4, 10, 20, 35, 56, 84, 120};

int main()
{
    int m;
    while (~scanf("%d", &m))
    {
        for (int i = 0; i < arr[m]; i++)
            for (int j = 0; j < arr[m]; j++)
                scanf("%lf", &brr[i][j]);
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &val[i]);
        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= arr[m]; j++)
                dp[i][j] = 0;
        for (int i = 0; i <= arr[m]; i++)
            dp[n + 1][i] = 1.0;
        for (int i = n; i >= 1; i--)
            for (int j = 0; j < arr[m]; j++)
                dp[i][j] = brr[j][val[i]] * max(dp[i + 1][j], dp[i + 1][val[i]]);
        double ans = -1;
        for (int i = 0; i < arr[m]; i++)
            ans = max(ans, dp[1][i]);
        printf("%.6f\n", ans);
    }
    return 0;
}