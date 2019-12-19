#include <bits/stdc++.h>

using namespace std;

const int N = 4e5 + 7;
const int NN = 5e3 + 7;
const int M = 2;

long long num[NN], pri[NN], fac[NN];
bool prime[N];
int p[N];
int cnt, factot, k;

struct Mat
{
    long long a[M][M];
} A;

Mat matmul(Mat a, Mat b, long long mod)
{
    Mat c = {0};
    for (int i = 0; i < M; i++)
        for (int j = 0; j < M; j++)
            for (int k = 0; k < M; k++)
                c.a[i][j] = (c.a[i][j] + (a.a[i][k] % mod) * (b.a[k][j] % mod) % mod) % mod;
    return c;
}

Mat matpow(Mat a, long long k, long long mod)
{
    Mat ans = {{1, 0, 0, 1}}, p = a;
    while (k)
    {
        if (k & 1)
            ans = matmul(ans, p, mod);
        k >>= 1;
        p = matmul(p, p, mod);
    }
    return ans;
}

void isprime()
{
    k = 0;
    memset(prime, true, sizeof(prime));
    for (int i = 2; i < N; i++)
    {
        if (prime[i])
        {
            p[k++] = i;
            for (int j = i + i; j < N; j += i)
                prime[j] = false;
        }
    }
}

long long qpow(long long a, long long b, long long mod)
{
    long long ans = 1;
    a %= mod;
    while (b)
    {
        if (b & 1)
            ans = ans * a % mod;
        b >>= 1;
        a = a * a % mod;
    }
    return ans;
}

// 勒让德公式
long long legendre(long long a, long long p)
{
    if (qpow(a, (p - 1) >> 1, p) == 1)
        return 1;
    else
        return -1;
}

// 质因子分解n
void factorize(long long n, long long pri[], long long num[])
{
    cnt = 0;
    long long t = (long long)sqrt(1.0 * n);
    for (int i = 0; p[i] <= t; i++)
    {
        if (n % p[i] == 0)
        {
            int a = 0;
            pri[cnt] = p[i];
            while (n % p[i] == 0)
            {
                a++;
                n /= p[i];
            }
            num[cnt] = a;
            cnt++;
        }
    }
    if (n > 1)
    {
        pri[cnt] = n;
        num[cnt] = 1;
        cnt++;
    }
}

// fac存n所有的因子
void work(long long n)
{
    factot = 0;
    long long t = (long long)sqrt(1.0 * n);
    for (int i = 1; i <= t; i++)
    {
        if (n % i == 0)
        {
            if (i * i == n)
                fac[factot++] = i;
            else
            {
                fac[factot++] = i;
                fac[factot++] = n / i;
            }
        }
    }
}

long long findloop(long long n)
{
    factorize(n, pri, num);
    long long ans = 1;
    for (int i = 0; i < cnt; i++)
    {
        long long record = 1;
        if (pri[i] == 2)
            record = 3;
        else if (pri[i] == 3)
            record = 8;
        else if (pri[i] == 5)
            record = 20;
        else
        {
            if (legendre(5, pri[i]) == 1)
                work(pri[i] - 1);
            else
                work(2 * (pri[i] + 1));
            sort(fac, fac + factot);
            for (int k = 0; k < factot; k++)
            {
                Mat a = matpow(A, fac[k] - 1, pri[i]);
                long long x = (a.a[0][0] % pri[i] + a.a[0][1] % pri[i]) % pri[i];
                long long y = (a.a[1][0] % pri[i] + a.a[1][1] % pri[i]) % pri[i];
                if (x == 1 && y == 0)
                {
                    record = fac[k];
                    break;
                }
            }
        }
        for (int k = 1; k < num[i]; k++)
            record *= pri[i];
        ans = ans / __gcd(ans, record) * record;
    }
    return ans;
}

int main()
{
    A = {{1, 1, 1, 0}};
    isprime();
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        long long n;
        scanf("%lld", &n);
        printf("Case #%d: %lld\n", cas, findloop(n));
    }
    return 0;
}