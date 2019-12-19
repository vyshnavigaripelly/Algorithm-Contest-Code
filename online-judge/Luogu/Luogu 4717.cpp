#include <iostream>
#include <cstring>

using namespace std;

const int N = (1 << 17) + 7;
const int mod = 998244353;
const int inv2 = 499122177; // 2 在 mod p 下的逆元

long long a[N], b[N], c[N], d[N];

enum FWT_OP
{
    FWT_AND,
    FWT_OR,
    FWT_XOR
};

void FWT(long long a[], int len, FWT_OP op, int flag)
{
    for (int i = 1; i < len; i <<= 1)
    {
        for (int j = 0; j < len; j += i << 1)
        {
            for (int k = 0; k < i; k++)
            {
                int u = a[j + k], t = a[j + k + i];
                if (op == FWT_AND)
                {
                    a[j + k] = (flag ? u + t : u - t + mod) % mod;
                }
                else if (op == FWT_OR)
                {
                    a[j + k + i] = (flag ? t + u : t - u + mod) % mod;
                }
                else if (op == FWT_XOR)
                {
                    a[j + k] = (u + t) % mod;
                    a[j + k + i] = (u - t + mod) % mod;
                    if (!flag)
                    {
                        a[j + k] = a[j + k] * inv2 % mod;
                        a[j + k + i] = a[j + k + i] * inv2 % mod;
                    }
                }
            }
        }
    }
}

void solveFWT(long long a[], long long b[], int len, FWT_OP op)
{
    FWT(a, len, op, 1);
    FWT(b, len, op, 1);
    for (int i = 0; i < len; i++)
        a[i] = a[i] * b[i] % mod;
    FWT(a, len, op, 0);
}

int main()
{
    int n;
    scanf("%d", &n);
    int m = 1 << n;
    for (int i = 0; i < m; i++)
        scanf("%lld", &a[i]);
    for (int i = 0; i < m; i++)
        scanf("%lld", &b[i]);

    memcpy(c, a, sizeof(a));
    memcpy(d, b, sizeof(b));
    solveFWT(c, d, m, FWT_OR);
    for (int i = 0; i < m; i++)
        printf("%lld ", c[i]);
    puts("");

    memcpy(c, a, sizeof(a));
    memcpy(d, b, sizeof(b));
    solveFWT(c, d, m, FWT_AND);
    for (int i = 0; i < m; i++)
        printf("%lld ", c[i]);
    puts("");

    memcpy(c, a, sizeof(a));
    memcpy(d, b, sizeof(b));
    solveFWT(c, d, m, FWT_XOR);
    for (int i = 0; i < m; i++)
        printf("%lld ", c[i]);
    puts("");
    return 0;
}