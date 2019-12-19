#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[10007];

int main()
{
    int n, q;
    for (int cas = 1; ~scanf("%d %d", &n, &q) && n && q; cas++)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr + 1, arr + 1 + n);
        printf("CASE# %d:\n", cas);
        while (q--)
        {
            int x;
            scanf("%d", &x);
            int ans = lower_bound(arr + 1, arr + 1 + n, x) - arr;
            if (arr[ans] == x)
            {
                printf("%d found at %d\n", x, ans);
            }
            else
            {
                printf("%d not found\n", x);
            }
        }
    }
    return 0;
}