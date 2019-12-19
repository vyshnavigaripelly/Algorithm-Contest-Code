#include <iostream>

using namespace std;

const int MAXN = 1e6 + 7;
const int MOD = 998244353;

long long prime[MAXN], fir[MAXN], sec[MAXN];

void getprime()
{
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main()
{
    getprime();
    int t;
    cin >> t;
    long long l, r, k;
    while (t--)
    {
        cin >> l >> r >> k;
        for (long long i = l, j = 1; i <= r; i++, j++)
        {
            fir[j] = 1;
            sec[j] = i;
        }
        for (long long i = 1; i <= prime[0]; i++)
        {
            long long tmp = (l + prime[i] - 1) / prime[i] * prime[i];
            for (long long j = tmp - l + 1; tmp <= r; j += prime[i])
            {
                int cnt = 0;
                while (!(sec[j] % prime[i]))
                {
                    cnt++;
                    sec[j] /= prime[i];
                }
                fir[j] *= cnt * k + 1;
                fir[j] %= MOD;
                tmp += prime[i];
            }
        }
        long long ans = 0;
        for (long long i = l, j = 1; i <= r; i++, j++)
        {
            if (sec[j] != 1)
                ans += fir[j] * (k + 1);
            else
                ans += fir[j];
            ans %= MOD;
        }
        cout << ans << endl;
    }
    return 0;
}