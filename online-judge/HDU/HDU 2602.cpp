#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct bone
{
    int weight, value;
} arr[1005];

int dp[1007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        memset(dp, 0, sizeof(dp));
        int n, v;
        cin >> n >> v;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].value;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].weight;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = v; j >= arr[i].weight; j--)
            {
                dp[j] = max(dp[j], dp[j - arr[i].weight] + arr[i].value);
            }
        }
        cout << dp[v] << endl;
    }
    return 0;
}