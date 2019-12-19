#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9 + 7;
const int N = 220;

int n;
long long A[N][N], a[N][N], C[N][N];

long long ext_gcd(long long a, long long b, long long &x, long long &y)
{
    if (b == 0)
    {
        x = 1, y = 0;
        return a;
    }
    long long d = ext_gcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}

long long inverse(long long a)
{
    long long x, y;
    ext_gcd(a, mod, x, y);
    return (x % mod + mod) % mod;
}

void add(long long &x, long long y)
{
    x += y;
    if (x >= mod)
        x -= mod;
}

long long guass_inverse()
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = i == j ? 1 : 0;
    for (int i = 0; i < n; i++)
    {
        int p = i;
        for (int j = i; j < n; j++)
            if (A[j][i] > A[p][i])
                p = j;
        swap(A[p], A[i]);
        swap(C[p], C[i]);
        if (A[i][i] == 0)
            return -1;
        long long inva = inverse(A[i][i]);
        for (int j = 0; j < n; j++)
        {
            C[i][j] = C[i][j] * inva % mod;
            A[i][j] = A[i][j] * inva % mod;
        }
        for (int j = 0; j < n; j++)
            if (j != i)
            {
                long long z = A[j][i];
                for (int k = 0; k < n; k++)
                {
                    add(C[j][k], mod - C[i][k] * z % mod);
                    add(A[j][k], mod - A[i][k] * z % mod);
                }
            }
    }
    return 1;
}

long long gauss(int n) ///高斯消元求行列式的值  用到了逆元把除法变乘法 避免精度问题
{
    long long ret = 1;
    int flag = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
            while (a[j][i])
            {
                long long tmp = a[i][i] / a[j][i];
                for (int k = i; k < n; k++)
                    ((a[i][k] -= a[j][k] * tmp % mod) += mod) %= mod;
                swap(a[i], a[j]);
                flag *= -1;
            }
        if (!a[i][i])
            return 0;
        (ret *= a[i][i]) %= mod;
    }
    return flag == -1 ? mod - ret : ret;
}

int main()
{
    srand(time(NULL));
    while (scanf("%d", &n) == 1)
    {
        for (int i = 0; i < n - 1; i++)
            for (int j = 0; j < n; j++)
                scanf("%lld", &A[i][j]);
        for (int i = 0; i < n; i++)
            A[n - 1][i] = rand() % n + 1;
        memcpy(a, A, sizeof(A));
        guass_inverse();
        long long invaa = gauss(n);
        long long t = (n - 1) % 2 ? -1 : 1;
        printf("%lld", (mod + t * invaa * C[0][n - 1] % mod) % mod);
        for (int i = 1; i < n; i++)
        {
            t = (n - 1 + i) % 2 ? -1 : 1;
            printf(" %lld", (mod + t * invaa * C[i][n - 1] % mod) % mod);
        }
        printf("\n");
    }
    return 0;
}