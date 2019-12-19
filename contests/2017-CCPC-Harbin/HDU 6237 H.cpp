#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;
const int M = 1000;

long long arr[N];
long long sum, num;
long long factor[M][2];
int n;
const int MAXN = 1e5 + 7;
int prime[MAXN + 1];

void getprime()
{
    memset(prime, 0, sizeof prime);
    for (int i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (int j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

int getfact(long long x)
{
    int fatcnt = 0;
    long long tmp = x;
    for (int i = 1; prime[i] <= tmp / prime[i]; i++)
    {
        factor[fatcnt][1] = 0;
        if (tmp % prime[i] == 0)
        {
            factor[fatcnt][0] = prime[i];
            while (tmp % prime[i] == 0)
            {
                factor[fatcnt][1]++;
                tmp /= prime[i];
            }
            fatcnt++;
        }
    }
    if (tmp != 1)
    {
        factor[fatcnt][0] = tmp;
        factor[fatcnt++][1] = 1;
    }
    return fatcnt;
}

long long sec[N];

long long check(long long x)
{
    long long res = 0, mmp = 0;
    int cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] % x)
        {
            sec[cnt] = arr[i] % x;
            mmp += sec[cnt];
            cnt++;
        }
    }
    sort(sec, sec + cnt);
    for (int r = cnt - 1; r >= 0 && mmp > 0; r--)
    {
        res += (x - sec[r]);
        mmp -= x;
    }
    return res;
}

int main()
{
    int T;
    getprime();
    cin >> T;
    while (T--)
    {
        long long ans = 0x3f3f3f3f3f3f3f3f;
        sum = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        num = getfact(sum);
        for (int i = 0; i < num; i++)
        {
            long long fir = check(factor[i][0]);
            ans = min(fir, ans);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
