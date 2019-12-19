#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int mod = 1e9 + 7;

struct Point
{
    long long x, y;

    bool operator==(const Point &b) { return x == b.x && y == b.y; }
    bool operator<(const Point &b) { return x < b.x || (x == b.x && y < b.y); }
};

Point arr[1007];
map<pair<long long, long long>, int> cnt;
long long pow2[1007];

int main()
{
    pow2[0] = 1;
    for (int i = 1; i < 1007; i++)
    {
        pow2[i] = pow2[i - 1] * 2 % mod;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr + n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int same = 0;
            cnt.clear();
            for (int j = i + 1; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    same++;
                    continue;
                }
                long long kx = arr[j].x - arr[i].x, ky = arr[j].y - arr[i].y;
                long long g = __gcd(kx, ky);
                cnt[{kx / g, ky / g}]++;
            }
            ans = (ans + pow2[same] - 1) % mod;
            for (auto i : cnt)
            {
                ans = (ans + pow2[same] * (pow2[i.second] - 1) % mod) % mod;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}