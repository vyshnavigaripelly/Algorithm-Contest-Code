#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> cnt, last;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            for (int j = 0; j < k; j++)
            {
                int x, y;
                scanf("%d %d", &x, &y);
                pair<int, int> p = {x, y};
                if (cnt[p] == 0 && last[p] == 0)
                {
                    cnt[p]++;
                }
                else if (cnt[p] != 0 && last[p] == i - 1)
                {
                    cnt[p]++;
                    ans = max(ans, cnt[p]);
                }
                else if (cnt[p] != 0 && last[p] != i && last[p] != i - 1)
                {
                    cnt[p] = 1;
                }
                last[p] = i;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}