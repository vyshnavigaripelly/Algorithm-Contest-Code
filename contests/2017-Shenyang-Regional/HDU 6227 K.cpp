#include <iostream>
#include <algorithm>
#include <cstring>
#include <numeric>
using namespace std;

int arr[1007], diff[1007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(diff, 0, sizeof(diff));
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
            if (i >= 1)
            {
                diff[i - 1] = arr[i] - arr[i - 1] - 1;
            }
        }
        long long ans = accumulate(diff, diff + n - 1, 0) - min(diff[0], diff[n - 2]);
        cout << ans << endl;
    }
    return 0;
}