#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

const int N = 1e5 + 7;
const int mod = 998244353;

int sum[11], arr[N];
long long ans;

long long calc(int x, int y, int flag)
{
    unsigned long long ans = 0, bit = flag;
    int num = x, len = (int)log10(x) + 1;
    if (flag == 10)
    {
        y--;
    }
    for (int i = 0; i < min(y, len); i++)
    {
        ans += num % 10 * bit;
        num /= 10;
        bit *= 100;
    }
    for (int i = 0; i < len - y; i++)
    {
        ans += num % 10 * bit;
        num /= 10;
        bit *= 10;
    }
    return ans % mod;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum[(int)log10(arr[i]) + 1]++;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int now = sum[j];
            if (now != 0)
            {
                (ans += now * calc(arr[i], j, 1) % mod) %= mod;
                (ans += now * calc(arr[i], j, 10) % mod) %= mod;
            }
        }
    }
    printf("%lld\n", ans % mod);
    return 0;
}