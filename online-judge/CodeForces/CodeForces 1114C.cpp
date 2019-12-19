#include <iostream>
#include <map>
#include <cmath>

using namespace std;

const int maxn = 1e6 + 7;

long long prime[maxn];
map<long long, long long> ind, cnt;

long long getcnt(long long p, long long x)
{
    long long res = 0;
    while (x)
    {
        res += x / p;
        x /= p;
    }
    return res;
}

int main()
{
    long long n, m;
    for (int i = 2; i <= maxn; i++)
    {
        if (!prime[i])
        {
            prime[++prime[0]] = i;
        }
        for (int j = 1; j <= prime[0] && prime[j] <= maxn / i; j++)
        {
            prime[prime[j] * i] = 1;
            if (i % prime[j] == 0)
            {
                break;
            }
        }
    }
    cin >> n >> m;
    long long mm = m;
    for (long long i = 1; sqrt(m) >= prime[i]; i++)
    {
        while (mm % prime[i] == 0)
        {
            ind[prime[i]]++;
            mm /= prime[i];
        }
    }
    if (mm != 1)
    {
        ind[mm]++;
    }
    for (long long i = 1; sqrt(m) >= prime[i]; i++)
    {
        if (ind[prime[i]])
        {
            cnt[prime[i]] = getcnt(prime[i], n);
        }
    }
    if (mm != 1)
    {
        cnt[mm] = getcnt(mm, n);
    }
    long long ans = 1e18 + 1;
    for (auto i = 1; sqrt(m) >= prime[i]; i++)
    {
        if (ind[prime[i]])
        {
            ans = min(ans, 1LL * cnt[prime[i]] / ind[prime[i]]);
        }
    }
    if (mm != 1)
    {
        ans = min(ans, 1LL * cnt[mm] / ind[mm]);
    }
    cout << ans << endl;
    return 0;
}