#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;

const int BUFSIZE = 50 * 1024 * 1024;
char Buf[BUFSIZE + 1], *buf = Buf;

template <class T>
void scan(T &a)
{
    int sgn = 1;
    for (a = 0; *buf < '0' || *buf > '9'; buf++)
        if (*buf == '-')
            sgn = -1;
    while (*buf >= '0' && *buf <= '9')
    {
        a = a * 10 + (*buf - '0');
        buf++;
    }
    a *= sgn;
}

void out(int x)
{
    if (x > 9)
        out(x / 10);
    putchar(x % 10 + '0');
}

long long pow_m(long long a, long long b, long long mod)
{
    long long res = 1;
    while (b)
    {
        if (b & 1)
            res = res * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}

long long inv(long long a, long long mod)
{
    return pow_m(a, mod - 2, mod);
}

const int N = 1000005;
long long ans[N], f[N];

int main()
{
    fread(Buf, 1, BUFSIZE, stdin);
    int T;
    scan(T);
    while (T--)
    {
        int n, q;
        scan(n), scan(q);
        for (int i = 1; i <= n; i++)
        {
            long long ri, si, xi, ai;
            long long sum = 0;
            scan(ri), scan(si), scan(xi), scan(ai);
            long long tmp = si % mod * inv(ri, mod) % mod;
            sum = tmp * ai % mod + (ans[i - 1] - ans[xi - 1] + mod) % mod * (si - ri) % mod * inv(ri, mod);
            sum %= mod;
            f[i] = (sum + mod) % mod;
            ans[i] = ans[i - 1] + f[i];
            ans[i] %= mod;
        }
        for (int i = 1; i <= q; i++)
        {
            int l, r;
            scan(l), scan(r);
            out((ans[r - 1] - ans[l - 1] + mod) % mod);
            puts("");
        }
    }
    return 0;
}
