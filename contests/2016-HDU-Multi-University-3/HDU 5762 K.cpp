#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

pair<long long, long long> arr[N];
long long dis[2 * N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(dis, 0, sizeof(dis));
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &arr[i].first, &arr[i].second);
        }
        sort(arr, arr + n);
        int cnt = 0, flag = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                long long tmp = abs(arr[i].first - arr[j].first) + abs(arr[i].second - arr[j].second);
                if (dis[tmp] == 0)
                {
                    cnt++;
                }
                else
                {
                    flag = 1;
                    break;
                }
                dis[tmp]++;
                if (cnt > 2 * (m + 1))
                {
                    flag = 1;
                    break;
                }
            }
        }
        puts(flag ? "YES" : "NO");
    }
    return 0;
}