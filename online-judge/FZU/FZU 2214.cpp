#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int w[507], v[507], dp[5007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(dp, 0x3f, sizeof(dp));
        dp[0] = 0;
        int n, b, sum = 0;
        cin >> n >> b;
        for (int i = 1; i <= n; i++)
        {
            cin >> w[i] >> v[i];
            sum += v[i];
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = sum; j >= v[i]; j--)
            {
                dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
            }
        }
        for (int i = sum; i >= 0; i--)
        {
            if (dp[i] <= b)
            {
                cout << i << endl;
                break;
            }
        }
    }
    return 0;
}