#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e4 + 7;

int arr[N], brr[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &brr[i]);
        }
        sort(arr, arr + n);
        sort(brr, brr + n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = lower_bound(brr, brr + n, arr[i]) - brr;
            ans += pos;
        }
        printf("Case %d: %.2f\n", cas, 1.0 * ans / n);
    }
    return 0;
}