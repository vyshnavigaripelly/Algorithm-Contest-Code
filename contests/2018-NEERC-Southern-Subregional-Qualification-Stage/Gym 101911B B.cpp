#include <iostream>

using namespace std;

const int N = 2e5 + 7;

int n, h;
int st[N], ed[N];
long long sumcost[N], sumvalue[N];

int main()
{
    scanf("%d %d", &n, &h);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &st[i], &ed[i]);
    }
    sumvalue[1] = ed[1] - st[1];
    for (int i = 2; i <= n; i++)
    {
        sumcost[i] = sumcost[i - 1] + st[i] - ed[i - 1];
        sumvalue[i] = sumvalue[i - 1] + ed[i] - st[i];
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int l = i, r = n, fpos = i;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (sumcost[mid] - sumcost[i] >= h)
            {
                r = mid - 1;
            }
            else
            {
                fpos = mid;
                l = mid + 1;
            }
        }
        ans = max(ans, sumvalue[fpos] - sumvalue[i - 1] + h);
    }
    cout << ans << endl;
    return 0;
}