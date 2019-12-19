#include <iostream>
#include <map>
using namespace std;

const int INF = 0x3f3f3f3f;

int arr[1000007];
map<int, int> mp;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        mp.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            mp[arr[i]]++;
        }
        int x = 1, y = INF;
        auto pre = mp.begin();
        while (pre->second < 2)
        {
            pre++;
        }
        if (pre->second >= 4)
        {
            int ans = pre->first;
            printf("%d %d %d %d\n", ans, ans, ans, ans);
        }
        else
        {
            auto cur = pre;
            for (cur++; cur != mp.end(); cur++)
            {
                if (cur->second >= 4)
                {
                    x = y = cur->first;
                    break;
                }
                else if (cur->second >= 2)
                {
                    double xx = pre->first, yy = cur->first;
                    if (1.0 * x / y + 1.0 * y / x > xx / yy + yy / xx)
                    {
                        x = pre->first, y = cur->first;
                    }
                    pre = cur;
                }
            }
            printf("%d %d %d %d\n", x, x, y, y);
        }
    }
    return 0;
}
