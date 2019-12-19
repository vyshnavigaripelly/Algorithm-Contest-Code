#include <iostream>
#include <map>
#include <tuple>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;

map<pair<long long, long long>, long long> mp;
map<tuple<long long, long long, long long>, long long> mp2;

struct Line
{
    long long sx, sy;
    long long ex, ey;
    long long a, b, c;

    void get()
    {
        a = -(sy - ey);
        b = sx - ex;
        c = -(sx * ey - sy * ex);
        if (a < 0 || (a == 0 && b < 0))
        {
            a = -a, b = -b, c = -c;
        }
        long long g = abs(__gcd(__gcd(a, b), c));
        a /= g, b /= g, c /= g;
    }
} arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        mp.clear();
        mp2.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld %lld %lld", &arr[i].sx, &arr[i].sy, &arr[i].ex, &arr[i].ey);
            arr[i].get();
            mp2[make_tuple(arr[i].a, arr[i].b, arr[i].c)]++;
            long long g = abs(__gcd(arr[i].a, arr[i].b));
            mp[{arr[i].a / g, arr[i].b / g}]++;
        }
        long long ans = 1LL * n * (n - 1) / 2;
        for (auto i : mp)
        {
            ans -= i.second * (i.second - 1) / 2;
        }
        for (auto i : mp2)
        {
            ans += i.second * (i.second - 1) / 2;
        }
        printf("%lld\n", ans);
    }
    return 0;
}