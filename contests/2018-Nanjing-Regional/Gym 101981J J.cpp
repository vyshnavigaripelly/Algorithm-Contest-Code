#include <bits/stdc++.h>

using namespace std;

const long long MAXN = 1e6 + 7;

long long prime[MAXN + 1];

void getprime()
{
    memset(prime, 0, sizeof(prime));
    for (long long i = 2; i <= MAXN; i++)
    {
        if (!prime[i])
            prime[++prime[0]] = i;
        for (long long j = 1; j <= prime[0] && prime[j] <= MAXN / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
                break;
        }
    }
}

long long arr[MAXN + 7];

vector<long long> vec[MAXN + 7];

int main()
{
    long long ans = 0;
    getprime();
    // for (long long i = 1; i <= 100; i++)
    //     cout << prime[i] << " ";
    long long n;
    cin >> n;
    for (long long i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
        long long tmp = arr[i];
        for (long long j = 1; prime[j] <= sqrt(tmp); j++)
        {
            if (tmp % prime[j] == 0)
            {
                vec[prime[j]].push_back(i);
                tmp /= prime[j];
                j--;
            }
        }
        if (tmp != 1)
            vec[tmp].push_back(i);
    }
    for (long long i = 1; i <= prime[0]; i++)
    {
        long long tar = prime[i];
        long long cnt = vec[tar].size();
        if (cnt)
        {
            long long prepos, pos;
            for (long long j = 0; j < cnt; j++)
            {
                pos = vec[tar][j];
                ans += (n - pos + 1) * pos;
                if (j > 0)
                {
                    ans -= prepos * (n + 1 - pos);
                }
                prepos = pos;
            }
        }
    }
    cout << ans << endl;
    return 0;
}