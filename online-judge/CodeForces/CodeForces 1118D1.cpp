#include <iostream>
#include <algorithm>

using namespace std;

int arr[107];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<int>());
    for (int ans = 1; ans <= n; ans++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += max(0, arr[i] - i / ans);
        }
        if (sum >= m)
        {
            cout << ans << endl;
            break;
        }
        if (ans == n)
        {
            cout << -1 << endl;
            break;
        }
    }
    return 0;
}