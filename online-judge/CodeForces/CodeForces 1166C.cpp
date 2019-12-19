#include <iostream>
#include <algorithm>

using namespace std;

long long arr[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    arr[n] = 1LL << 62;
    long long ans = 0;
    for (int i = 0; i < n - 1; i++)
    {
        long long now = arr[i];
        if (arr[i] < 0)
        {
            now = -now;
        }
        long long r1 = lower_bound(arr, arr + n + 1, 2LL * now) - arr;
        if (r1 == n || arr[r1] != 2LL * now)
        {
            r1--;
        }
        if (arr[i] < 0)
        {
            now = (now + 1) / 2;
            long long r2 = lower_bound(arr, arr + n + 1, now) - arr;
            now = (arr[i] - 1) / 2;
            long long r3 = lower_bound(arr, arr + n + 1, now) - arr;
            if (r3 == n || arr[r3] != now)
            {
                r3--;
            }
            ans += max(0LL, r1 - r2 + 1);
            ans += max(0LL, r3 - i);
        }
        else
        {
            ans += max(0LL, r1 - i);
        }
    }
    cout << ans << endl;
    return 0;
}