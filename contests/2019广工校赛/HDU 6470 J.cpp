#include <bits/stdc++.h>
using namespace std;
#define N 10
#define MOD 123456789
long long T, n;

struct Matrix
{
    long long n, m, f[N][N];
    void print()
    {
        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= m; j++)
                printf("%lld%c", f[i][j], j < m ? ' ' : '\n');
        cout << endl;
    }
    void init(long long nn, long long mm)
    {
        n = nn, m = mm;
        for (long long i = 0; i <= n; i++)
            for (long long j = 0; j <= m; j++)
                f[i][j] = 0;
    }
    void set_E(long long nn)
    {
        n = m = nn;
        for (long long i = 0; i <= n; i++)
            f[i][i] = 1;
    }
    Matrix operator*(const Matrix &t) const
    {
        Matrix res;
        res.init(n, t.m);
        for (long long i = 1; i <= n; i++)
            for (long long j = 1; j <= t.m; j++)
                for (long long k = 1; k <= m; k++)
                    (res.f[i][j] += f[i][k] * t.f[k][j] % MOD) %= MOD;
        return res;
    }
    Matrix operator^(long long k) const
    {
        Matrix base = *this, res;
        res.init(n, n);
        res.set_E(n);
        while (k > 0)
        {
            if (k & 1)
                res = res * base;
            base = base * base;
            k >>= 1;
        }
        return res;
    }
} p, q;

int main()
{
    p.init(6, 1);
    q.init(6, 6);
    q.f[1][1] = q.f[2][2] = q.f[3][3] = q.f[4][4] = q.f[1][4] = q.f[2][4] = q.f[3][4] = q.f[5][1] = q.f[5][4] = 1;
    q.f[1][2] = q.f[1][3] = q.f[5][2] = q.f[5][3] = 3;
    q.f[2][3] = 2;
    q.f[5][5] = q.f[6][5] = 1;
    q.f[5][6] = 2;
    p.f[1][1] = 8, p.f[2][1] = 4, p.f[3][1] = 2, p.f[4][1] = 1, p.f[5][1] = 2, p.f[6][1] = 1;
    scanf("%lld", &T);
    for (long long i = 1; i <= T; i++)
    {
        scanf("%lld", &n);
        long long ans;
        if (n == 1)
        {
            ans = 1;
        }
        else if (n == 2)
        {
            ans = 2;
        }
        else
        {
            ans = ((q ^ (n - 2)) * p).f[5][1];
        }
        printf("%lld\n", ans);
    }
}
