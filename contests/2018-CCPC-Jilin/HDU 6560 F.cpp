#include <iostream>
#include <cstdio>

using namespace std;

int arr[1000007];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, ans = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            ans ^= max(arr[i] - 2, 0);
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}