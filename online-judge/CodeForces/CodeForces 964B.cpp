#include <iostream>
#include <algorithm>
using namespace std;

int arr[1010];

int main()
{
    int n, a, b, c, t, ans = 0;
    cin >> n >> a >> b >> c >> t;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (c > b)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= t)
            {
                ans += (t - arr[i]) * (c - b) + a;
            }
        }
    }
    else
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] <= t)
            {
                cnt++;
            }
        }
        ans = a * cnt;
    }
    cout << ans << endl;
}
