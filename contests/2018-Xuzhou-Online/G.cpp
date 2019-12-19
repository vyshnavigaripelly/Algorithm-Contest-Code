#include <iostream>
#include <set>
#include <functional>

using namespace std;

const int N = 1e5 + 7;

set<int> length, width;
pair<int, int> pp[N];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        pp[i] = make_pair(x, y);
    }
    long long ans = 0;
    length.insert(pp[n].first);
    width.insert(pp[n].second);
    ans += pp[n].first + pp[n].second;
    for (int i = n - 1; i >= 1; i--)
    {
        auto it1 = length.lower_bound(pp[i].first), it2 = width.lower_bound(pp[i].second);
        ans += it1 == length.begin() ? pp[i].first : pp[i].first - *(--it1);
        ans += it2 == width.begin() ? pp[i].second : pp[i].second - *(--it2);
        length.insert(pp[i].first);
        width.insert(pp[i].second);
    }
    printf("%lld\n", ans);
    return 0;
}