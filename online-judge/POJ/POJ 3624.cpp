#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

struct charm
{
    int w, d;
} arr[3507];

int dp[13007];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].w >> arr[i].d;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = m; j >= arr[i].w; j--)
        {
            dp[j] = max(dp[j], dp[j - arr[i].w] + arr[i].d);
        }
    }
    cout << dp[m] << endl;
    return 0;
}