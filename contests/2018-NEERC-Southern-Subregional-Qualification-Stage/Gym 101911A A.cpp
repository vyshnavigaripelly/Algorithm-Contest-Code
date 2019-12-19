#include <iostream>
#include <set>

using namespace std;

struct Node
{
    int val;
    int pos;
    int ans;
} arr[200007];

set<pair<int, int>> se;

int main()
{
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i].val);
        arr[i].pos = i;
        se.insert({arr[i].val, i});
    }
    int last = -d - 7, day = 1;
    while (!se.empty())
    {
        auto now = se.lower_bound({last + d + 1, -1});
        if (now == se.end())
        {
            day++;
            now = se.begin();
        }
        last = (*now).first;
        arr[(*now).second].ans = day;
        se.erase(now);
    }
    printf("%d\n", day);
    for (int i = 1; i <= n; i++)
    {
        printf("%d ", arr[i].ans);
    }
    return 0;
}