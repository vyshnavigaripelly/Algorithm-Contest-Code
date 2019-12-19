#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 507;

int arr[N][N], minn[N], maxn[N];
deque<int> quemax, quemin;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                scanf("%d", &arr[i][j]);
            }
        }
        int ans = 1;
        for (int u = 0; u < n; u++)
        {
            memset(minn, 0x3f, sizeof(minn));
            memset(maxn, 0xcf, sizeof(maxn));
            for (int d = u; d < n; d++)
            {
                for (int i = 0; i < n; i++)
                {
                    minn[i] = min(minn[i], arr[d][i]);
                    maxn[i] = max(maxn[i], arr[d][i]);
                }
                int l = 0;
                quemin.clear();
                quemax.clear();
                for (int r = 0; r < n; r++)
                {
                    while (!quemin.empty() && minn[quemin.back()] >= minn[r])
                    {
                        quemin.pop_back();
                    }
                    while (!quemax.empty() && maxn[quemax.back()] <= maxn[r])
                    {
                        quemax.pop_back();
                    }
                    quemin.push_back(r);
                    quemax.push_back(r);
                    while (l <= r && maxn[quemax.front()] - minn[quemin.front()] > m)
                    {
                        l++;
                        if (quemin.front() < l)
                        {
                            quemin.pop_front();
                        }
                        if (quemax.front() < l)
                        {
                            quemax.pop_front();
                        }
                    }
                    ans = max(ans, (r - l + 1) * (d - u + 1));
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}