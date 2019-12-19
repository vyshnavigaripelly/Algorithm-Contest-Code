#include <iostream>
#include <algorithm>
using namespace std;

int arr[150];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n, greater<int>());
        int ans = 0, cur = 0;
        for (int i = 0; i < n; i++)
        {
            cur += (100 - arr[i]);
            if (cur > m)
            {
                break;
            }
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}