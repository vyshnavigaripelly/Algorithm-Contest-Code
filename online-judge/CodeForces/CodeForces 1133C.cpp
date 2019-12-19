#include <iostream>
#include <algorithm>

using namespace std;

int arr[200007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int tmp = upper_bound(arr, arr + n, arr[i] + 5) - arr;
        ans = max(ans, tmp - i);
    }
    cout << ans << endl;
    return 0;
}