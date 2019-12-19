#include <iostream>
#include <cstdio>

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
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &brr[i]);
            if (arr[i] + brr[i] > 10)
                ans++;
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}