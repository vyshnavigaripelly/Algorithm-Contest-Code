#include <iostream>

using namespace std;

const int mod = 1e9 + 7;

long long arr[3], dp[200017][3];

void solve(long long &a, long long b)
{
    a += b;
    while (a >= mod)
    {
        a -= mod;
    }
}

int main()
{
    long long n, l, r;
    cin >> n >> l >> r;
    arr[l % 3] = (r - l + 3) / 3;
    arr[(l + 1) % 3] = (r - l + 2) / 3;
    arr[(l + 2) % 3] = (r - l + 1) / 3;
    dp[0][0] = 1;
    dp[0][1] = dp[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = dp[i][1] = dp[i][2] = 0;

        solve(dp[i][0], arr[0] * dp[i - 1][0] % mod);
        solve(dp[i][0], arr[1] * dp[i - 1][2] % mod);
        solve(dp[i][0], arr[2] * dp[i - 1][1] % mod);

        solve(dp[i][1], arr[0] * dp[i - 1][1] % mod);
        solve(dp[i][1], arr[1] * dp[i - 1][0] % mod);
        solve(dp[i][1], arr[2] * dp[i - 1][2] % mod);

        solve(dp[i][2], arr[0] * dp[i - 1][2] % mod);
        solve(dp[i][2], arr[1] * dp[i - 1][1] % mod);
        solve(dp[i][2], arr[2] * dp[i - 1][0] % mod);
    }
    cout << dp[n][0] << endl;
}