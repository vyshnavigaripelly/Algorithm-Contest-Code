#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long ans[57][57], q;
int n, k;

long long fun(int x)
{
    long long ans = 1;
    for (int i = 2; i <= x; i++)
    {
        ans *= i;
        ans %= q;
    }
    return ans % q;
}

int main()
{
    ios::sync_with_stdio(false);
    int t;
    cin >> t;
    ans[3][1] = 5, ans[3][2] = 6, ans[4][1] = 10, ans[4][2] = 14;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> n >> k >> q;
        for (int i = 3; i <= n; i++)
        {
            ans[i][i] = fun(i);
            ans[i + 1][i] = fun(i + 1);
        }
        for (int i = 5; i <= n; i++)
        {
            for (int j = 1; j < i - 1; j++)
            {
                ans[i][j] = ((2 * ans[i - 1][j] % q - ans[i - 2][j] % q + q) % q + 2 * fun(j)) % q;
            }
        }
        cout << "Case #" << cas << ": ";
        if (k >= n - 1)
            cout << fun(n) << endl;
        else
            cout << ans[n][k] % q << endl;
    }
    return 0;
}
