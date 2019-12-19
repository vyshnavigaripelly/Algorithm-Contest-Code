#include <iostream>

using namespace std;

int arr[1007], flag[1007];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    arr[0] = arr[n + 1] = k;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arr[i] + arr[i - 1] < k)
        {
            ans += k - arr[i] - arr[i - 1];
            arr[i] = k - arr[i - 1];
        }
    }
    cout << ans << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}