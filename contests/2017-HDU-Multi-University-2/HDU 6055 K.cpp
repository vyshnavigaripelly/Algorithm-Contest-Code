#include <iostream>
#include <map>
#include <set>
#include <cstdio>

using namespace std;

set<pair<int, int>> se;
pair<int, int> a[507];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        se.clear();
        for (int i = 0; i < n; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            a[i] = {x, y};
            se.insert({x, y});
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                {
                    continue;
                }
                int dx = a[j].second - a[i].second;
                int dy = -(a[j].first - a[i].first);
                pair<int, int> aa = {a[i].first + dx, a[i].second + dy},
                               bb = {a[j].first + dx, a[j].second + dy};
                if (se.count(aa) && se.count(bb))
                {
                    cnt++;
                }
            }
        }
        printf("%d\n", cnt / 4);
    }
    return 0;
}