#include <iostream>
#include <algorithm>

using namespace std;

int arr[17];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int ans = 3 * arr[0];
        for (int i = 0; i < n; i++)
        {
            ans = max(ans, arr[i] + 1);
        }
        if (ans % 2 == 1)
            ans++;
        printf("%lld\n", ans);
    }
    return 0;
}