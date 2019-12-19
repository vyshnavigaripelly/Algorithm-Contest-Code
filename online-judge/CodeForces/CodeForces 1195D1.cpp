#include <iostream>

using namespace std;

const int mod = 998244353;

long long sum[20];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        long long k, dig = 0;
        cin >> k;
        while (k != 0)
        {
            long long now = k % 10;
            k /= 10;
            (sum[dig] += now * n) %= mod;
            (sum[dig + 1] += now * n) %= mod;
            dig += 2;
        }
    }
    long long ans = 0, mul = 1;
    for (int i = 0; i < 20; i++)
    {
        ans = (ans + mul * sum[i]) % mod;
        mul = 10 * mul % mod;
    }
    cout << ans << endl;
    return 0;
}