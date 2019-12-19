#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<pair<int, int>, int> mp;
pair<int, int> p[1007];

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        p[i].first = x * 2;
        p[i].second = y * 2;
        mp[p[i]]++;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + 1; j <= n; j++)
        {
            if (p[i] != p[j])
            {
                mp[{(p[i].first + p[j].first) / 2, (p[i].second + p[j].second) / 2}] += 2;
            }
        }
    }
    int ans = n;
    for (auto i : mp)
    {
        ans = min(ans, n - i.second);
    }
    printf("%d\n", ans);
    return 0;
}
