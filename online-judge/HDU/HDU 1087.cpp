#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int arr[1007], dp[1007];

int main()
{
    int n;
    while (cin >> n && n)
    {
        memset(dp, 0, sizeof(dp));
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
            dp[i] = arr[i];
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 1; j < i; j++)
            {
                if (arr[j] < arr[i] && dp[i] < dp[j] + arr[i])
                {
                    dp[i] = max(dp[i], dp[j] + arr[i]);
                }
            }
        }
        cout << *max_element(dp + 1, dp + 1 + n) << endl;
    }
    return 0;
}
