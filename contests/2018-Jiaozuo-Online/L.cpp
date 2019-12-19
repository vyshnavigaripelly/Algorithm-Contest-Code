#include <algorithm>
#include <cassert>
#include <cstdio>
#include <vector>
using namespace std;

#define SZ(x) ((long long)(x).size())

const long long mod = 1000000007;

long long FastPow(long long x, long long n)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % mod;
        x = x * x % mod;
        n >>= 1;
    }
    return s;
}

namespace linear_seq
{
    const int N = 10010;
    long long res[N], base[N], _c[N], _md[N];

    vector<long long> Md;

    void mul(long long *a, long long *b, long long k)
    {
        for (int i = 0; i < k + k; i++)
            _c[i] = 0;
        for (int i = 0; i < k; i++)
            if (a[i])
                for (int j = 0; j < k; j++)
                    _c[i + j] = (_c[i + j] + a[i] * b[j]) % mod;
        for (long long i = k + k - 1; i >= k; i--)
            if (_c[i])
                for (int j = 0; j < SZ(Md); j++)
                    _c[i - k + Md[j]] = (_c[i - k + Md[j]] - _c[i] * _md[Md[j]]) % mod;
        for (int i = 0; i < k; i++)
            a[i] = _c[i];
    }

    long long solve(long long n, vector<long long> a, vector<long long> b)
    {
        // a 系数 b 初值 b[n+1]=a[0]*b[n]+...
        //        printf("%d\n",SZ(b));
        long long ans = 0, pnt = 0;
        long long k = SZ(a);
        assert(SZ(a) == SZ(b));
        for (int i = 0; i < k; i++)
            _md[k - 1 - i] = -a[i];
        _md[k] = 1;
        Md.clear();
        for (int i = 0; i < k; i++)
            if (_md[i] != 0)
                Md.push_back(i);
        for (int i = 0; i < k; i++)
            res[i] = base[i] = 0;
        res[0] = 1;
        while ((1LL << pnt) <= n)
            pnt++;
        for (long long p = pnt; p >= 0; p--)
        {
            mul(res, res, k);
            if ((n >> p) & 1)
            {
                for (long long i = k - 1; i >= 0; i--)
                    res[i + 1] = res[i];
                res[0] = 0;
                for (int j = 0; j < SZ(Md); j++)
                    res[Md[j]] = (res[Md[j]] - res[k] * _md[Md[j]]) % mod;
            }
        }
        for (int i = 0; i < k; i++)
            ans = (ans + res[i] * b[i]) % mod;
        if (ans < 0)
            ans += mod;
        return ans;
    }

    vector<long long> BM(vector<long long> s)
    {
        vector<long long> C(1, 1), B(1, 1);
        long long L = 0, m = 1, b = 1;
        for (int n = 0; n < SZ(s); n++)
        {
            long long d = 0;
            for (int i = 0; i < L + 1; i++)
                d = (d + (long long)C[i] * s[n - i]) % mod;
            if (d == 0)
                ++m;
            else if (2 * L <= n)
            {
                vector<long long> T = C;
                long long c = mod - d * FastPow(b, mod - 2) % mod;
                while (SZ(C) < SZ(B) + m)
                    C.push_back(0);
                for (int i = 0; i < SZ(B); i++)
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                L = n + 1 - L;
                B = T;
                b = d;
                m = 1;
            }
            else
            {
                long long c = mod - d * FastPow(b, mod - 2) % mod;
                while (SZ(C) < SZ(B) + m)
                    C.push_back(0);
                for (int i = 0; i < SZ(B); i++)
                    C[i + m] = (C[i + m] + c * B[i]) % mod;
                ++m;
            }
        }
        return C;
    }

    long long gao(vector<long long> a, long long n)
    {
        vector<long long> c = BM(a);
        c.erase(c.begin());
        for (int i = 0; i < SZ(c); i++)
            c[i] = (mod - c[i]) % mod;
        return solve(n, c, vector<long long>(a.begin(), a.begin() + SZ(c)));
    }
};

long long t, n;

int main()
{
    vector<long long> seq{3, 9, 20, 46, 106, 244, 560, 1286, 2956, 6794};
    scanf("%lld", &t);
    while (t--)
    {
        scanf("%lld", &n);
        printf("%lld\n", linear_seq::gao(seq, n - 1) % mod);
    }
    return 0;
}