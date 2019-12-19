#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

long long arr[100007], sum[100007];

int main()
{
    int n, k, m;
    cin >> n >> k >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + 1LL * arr[i];
    }
    double ans = 0;
    for (int i = 0; i <= min(m, n - 1); i++)
    {
        long long tmp = sum[n] - sum[i] + min(1LL * k * (n - i), 1LL * (m - i));
        ans = max(ans, 1.0 * tmp / (n - i));
    }
    printf("%f\n", ans);
}