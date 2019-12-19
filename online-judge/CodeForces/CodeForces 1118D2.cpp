#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

long long arr[200007];

int check(int mid)
{
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += max(0LL, arr[i] - i / mid);
    }
    if (sum >= m)
    {
        return 1;
    }
    return 0;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<long long>());
    long long l = 1, r = n, ans = -1;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (check(mid))
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}