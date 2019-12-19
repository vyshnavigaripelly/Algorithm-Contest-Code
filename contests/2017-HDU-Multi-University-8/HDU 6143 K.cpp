#include <bits/stdc++.h>

using namespace std;

const int N = 2e3 + 7;
const int mod = 1e9 + 7;
const int INF = 2e3 + 7;

typedef long long ll;

ll arr[N][N], fac[N], fir[N][N];

ll pow_m(ll a, ll b, ll c)
{
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % c;
        a = a * a % c;
        b >>= 1;
    }
    return res;
}

int main()
{
    int n, m, t;
    cin >> t;
    arr[1][1] = 1;
    for (int i = 2; i < INF; i++)
        for (int j = 1; j <= i; j++)
            arr[i][j] = (arr[i - 1][j - 1] + j * arr[i - 1][j] * 1LL) % mod;
    fac[0] = fac[1] = 1;
    for (int i = 2; i < INF; i++)
        fac[i] = fac[i - 1] * i % mod;
    for (int i = 1; i < INF; i++)
        for (int j = 0; j <= i; j++)
            ((i == j || !j) ? fir[i][j] = 1 : (fir[i][j] = (fir[i - 1][j] + fir[i - 1][j - 1]) % mod));
    while (t--)
    {
        ll ans = 0;
        cin >> n >> m;
        for (int i = 1; i <= min(n, m - 1); i++)
        {
            ans = (ans + arr[n][i] * fac[i] % mod * pow_m(m - i, n, mod) % mod * fir[m][i] % mod) % mod;
        }
        cout << ans % mod << endl;
    }
    return 0;
}