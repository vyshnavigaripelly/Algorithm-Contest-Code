#include <iostream>
#include <algorithm>

using namespace std;

int arr[100007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int ans = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= ans)
        {
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}