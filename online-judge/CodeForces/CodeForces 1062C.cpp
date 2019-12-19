#include <iostream>

using namespace std;

int one[100007], zero[100007];

const int mod = 1e9 + 7;

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

int main()
{
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        if (i > 0)
        {
            zero[i + 1] = zero[i];
            one[i + 1] = one[i];
        }
        if (s[i] == '0')
        {
            zero[i + 1]++;
        }
        else
        {
            one[i + 1]++;
        }
    }
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long ans = (FastPow(2, one[r] - one[l - 1], mod) - 1 + mod) % mod * FastPow(2, zero[r] - zero[l - 1], mod) % mod;
        cout << ans << endl;
    }
    return 0;
}