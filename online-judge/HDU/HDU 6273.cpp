#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int maxn = 100005, mod = 998244353;
int two[maxn], three[maxn];

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
    return s;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(two, 0, sizeof(two));
        memset(three, 0, sizeof(three));
        int n, m;
        scanf("%d %d", &n, &m);
        while (m--)
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            if (x == 2)
            {
                two[l]++;
                two[r + 1]--;
            }
            else
            {
                three[l]++;
                three[r + 1]--;
            }
        }
        int minTwo = two[1], minThree = three[1];
        for (int i = 2; i <= n; i++)
        {
            two[i] += two[i - 1];
            three[i] += three[i - 1];
            if (two[i] < minTwo)
            {
                minTwo = two[i];
            }
            if (three[i] < minThree)
            {
                minThree = three[i];
            }
        }
        printf("%lld\n", FastPow(2, minTwo, mod) * FastPow(3, minThree, mod) % mod);
    }
    return 0;
}
