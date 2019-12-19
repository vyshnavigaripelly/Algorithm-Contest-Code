#include <iostream>
#include <set>
#include <algorithm>
#include <map>

using namespace std;

const int N = 1e5 + 7;
const long long INF = 1LL << 62;

struct Node
{
    long long x, y;
    int id;
} arr[N];

set<pair<long long, int>> y;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        y.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &arr[i].x, &arr[i].y);
            arr[i].id = i;
            y.insert({arr[i].y, i});
        }
        long long maxy = -INF;
        y.insert({-INF, -2});
        y.insert({-INF, -1});
        y.insert({INF, -1});
        sort(arr, arr + n, [](const Node &a, const Node &b) {
            return a.x > b.x;
        });
        long long ans = INF;
        for (int i = 0; i < n; i++)
        {
            y.erase({arr[i].y, arr[i].id});
            auto it2 = y.lower_bound({arr[i].x, -1});
            if (it2->first == INF)
            {
                --it2;
            }
            auto it = it2;
            --it;
            if (it->first == -INF)
            {
                ++it;
            }
            long long y1 = it->first, y2 = it2->first;
            long long yy = abs(arr[i].x - y1) < abs(arr[i].x - y2) ? y1 : y2;
            if (maxy >= max(y1, y2))
            {
                ans = min(ans, abs(arr[i].x - maxy));
            }
            else
            {
                ans = min({ans, abs(arr[i].x - yy), abs(arr[i].x - maxy)});
            }
            maxy = max(maxy, arr[i].y);
        }
        printf("%lld\n", ans);
    }
    return 0;
}