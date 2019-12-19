#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

struct bank
{
    int value, weight;
} arr[550];

int dp[100005];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        int e, f;
        cin >> e >> f;
        int maxw = f - e;
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = arr[i].weight; j <= maxw; j++)
            {
                dp[j] = min(dp[j], dp[j - arr[i].weight] + arr[i].value);
            }
        }
        if (dp[maxw] != 0x3f3f3f3f)
        {
            printf("The minimum amount of money in the piggy-bank is %d.\n", dp[maxw]);
        }
        else
        {
            puts("This is impossible.");
        }
    }
    return 0;
}