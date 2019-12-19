#include <iostream>
#define MOD 1000000007
using namespace std;

long long pow_m(long long a, long long n)
{
    long long ret = 1;
    long long tmp = a % MOD;
    while (n)
    {
        if (n & 1)
            ret = (ret * tmp) % MOD;
        tmp = tmp * tmp % MOD;
        n >>= 1;
    }
    return ret % MOD;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m, ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            ans += pow_m(i, m);
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}
