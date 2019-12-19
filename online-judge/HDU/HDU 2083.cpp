#include <iostream>
#include <algorithm>
using namespace std;

int arr[1007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        int ans = 0, start = arr[n / 2];
        for (int i = 0; i < n; i++)
        {
            ans += abs(start - arr[i]);
        }
        cout << ans << endl;
    }
    return 0;
}