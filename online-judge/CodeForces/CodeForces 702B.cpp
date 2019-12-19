#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100007];
long long mi[35] = {2, 4};

int main()
{
    for (int i = 2; i < 30; i++)
    {
        mi[i] = 2 * mi[i - 1];
    }
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 30; j++)
        {
            long long b = mi[j] - arr[i];
            int l = lower_bound(arr + i + 1, arr + n, b) - arr;
            int r = upper_bound(arr + i + 1, arr + n, b) - arr;
            if (b > 0 && arr[l] == b)
            {
                ans += r - l;
            }
        }
    }
    cout << ans << endl;
    return 0;
}