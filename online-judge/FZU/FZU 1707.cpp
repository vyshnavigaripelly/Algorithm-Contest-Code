#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool vis[int(2e7 + 5)];
int arr[5007];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(vis, 0, sizeof(vis));
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            vis[arr[i] + int(1e7)] = 1;
        }
        int ans = 0;
        sort(arr, arr + n);
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int sum = arr[i] + arr[j];
                if (sum > arr[n - 1])
                {
                    break;
                }
                else if (sum < -1e7)
                {
                    continue;
                }
                else if (arr[i] == 0 || arr[j] == 0)
                {
                    continue;
                }
                else if (vis[sum + int(1e7)] == 1)
                {
                    ans++;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}