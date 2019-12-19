#include <iostream>
using namespace std;

const long long mod = 1e9 + 7;
const long long maxn = 1e6 + 7;

long long c[maxn], inv[maxn];
long long n, m, k;

long long FastPow(long long x, long long n, long long mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}

void calinv()
{
    for (int i = 1; i < maxn; i++)
    {
        inv[i] = FastPow(i, mod - 2, mod);
    }
}

void initc(int n)
{
    c[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        c[i] = ((c[i - 1] * (n - i + 1) % mod) * inv[i] % mod) % mod;
    }
}

int main()
{
    calinv();
    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        cin >> n >> m >> k;
        long long ans = 0, sign = (k % 2 == 1 ? 1 : -1);
        initc(k);
        for (int i = 1; i <= k; i++)
        {
            ans = (ans + sign * i % mod * c[i] % mod * FastPow(i - 1, n - 1, mod) + mod) % mod;
            sign = -sign;
        }
        initc(m);
        ans = ans * c[k] % mod;
        cout << "Case #" << cas << ": " << ans << endl;
    }
    return 0;
}