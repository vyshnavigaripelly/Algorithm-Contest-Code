#include <iostream>

using namespace std;

const long long mod = 1e9 + 7;
const long long maxn = 1e5 + 7;

long long c[maxn], inv[maxn];

long long FastPow(long long x, long long n, long long mod)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
        {
            s = s * x % mod;
        }
        x = x * x % mod;
        n >>= 1;
    }
    return s % mod;
}
void makeinv()
{
    for (int i = 1; i < maxn; i++)
    {
        inv[i] = FastPow(i, mod - 2, mod);
    }
}

void makec(int n, int maxlen)
{
    c[0] = 1;
    for (int i = 1; i <= maxlen; i++)
    {
        c[i] = ((c[i - 1] * (n - i + 1) % mod) * inv[i] % mod) % mod;
    }
}

int main()
{
    makeinv();
    int t, cas = 1;
    cin >> t;
    while (cas <= t)
    {
        long long n, k;
        cin >> n >> k;
        long long ans = FastPow(2, n, mod), ans2 = 0;
        makec(n, k);
        for (int i = 0; i <= k - 1; i++)
        {
            ans2 = (ans2 + c[i]) % mod;
        }
        ans = (ans - ans2 + mod) % mod;
        cout << "Case #" << cas << ": " << ans << endl;
        cas++;
    }
    return 0;
}