#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 1;
const int mod = 1e9 + 7;

map<long long, long long> cnt;
map<long long, long long> gcd[2];
long long arr[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        cnt[arr[i]]++;
        gcd[(i + 1) % 2][arr[i]]++;
        for (auto j : gcd[i % 2])
        {
            long long g = __gcd(arr[i], j.first);
            gcd[(i + 1) % 2][g] += j.second;
            cnt[g] += j.second;
        }
        gcd[i % 2].clear();
    }
    long long ans = 0;
    for (auto i : cnt)
    {
        ans = (ans + (i.first % mod) * (i.second % mod) % mod) % mod;
    }
    printf("%lld\n", ans % mod);
    return 0;
}
