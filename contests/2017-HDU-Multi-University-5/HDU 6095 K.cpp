#include <iostream>
#include <algorithm>

using namespace std;

int arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr + 1, arr + 1 + n);
        int ans = 1;
        for (int i = n; i >= 2; i--)
        {
            if (abs(arr[i] - arr[i - 1]) <= k)
            {
                ans++;
            }
            else
            {
                break;
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}