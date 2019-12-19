#include <iostream>
#include <algorithm>

using namespace std;

pair<long long, long long> arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i].first);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i].second);
        }
        sort(arr, arr + n);
        int i;
        long long sum = 0;
        for (i = 0; i < n; i++)
        {
            if (sum + arr[i].second > m)
            {
                break;
            }
            sum += arr[i].second;
        }
        printf("Case %d: %d\n", cas, i);
    }
    return 0;
}