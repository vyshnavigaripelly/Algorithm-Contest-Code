#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1e9 + 7;

char str[100007], tmp[100007];

long long qpow(long long a, long long b = mod - 2, long long m = mod)
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

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", tmp);
        int len = strlen(tmp);
        int allzero = 1;
        for (int i = len - 1; i >= 0; i--)
        {
            str[i] = tmp[len - 1 - i];
            if (str[i] == '1')
                allzero = 0;
        }
        if (allzero)
        {
            puts("1");
            continue;
        }
        int first = 1;
        long long ans = 0, zero;
        for (int i = len - 1; i >= 0; i--)
        {
            if (str[i] == '0')
                continue;
            if (first)
            {
                ans = (ans + qpow(2, i) + 1) % mod;
                first = 0;
                zero = i;
            }
            else
            {
                ans = (ans + (ans + 1) * qpow(2) % mod + qpow(2, i) - 1 + mod) % mod;
            }
            zero--;
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}