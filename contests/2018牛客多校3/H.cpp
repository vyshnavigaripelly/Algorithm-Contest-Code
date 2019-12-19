#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int MAXN = 1e7 + 5;

int notprime[MAXN], sum[MAXN];

void init()
{
    memset(notprime, false, sizeof(notprime));
    notprime[0] = notprime[1] = 1;
    for (int i = 2; i < MAXN; i++)
    {
        if (!notprime[i])
        {
            if (i > MAXN / i)
            {
                continue;
            }
            for (int j = i * i; j < MAXN; j += i)
            {
                notprime[j] = 1;
            }
        }
    }
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + (!notprime[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        long long tmp = sum[n / i];
        ans += tmp * (tmp - 1);
    }
    printf("%lld\n", ans);
    return 0;
}