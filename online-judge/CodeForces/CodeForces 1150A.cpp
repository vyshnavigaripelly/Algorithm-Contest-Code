#include <iostream>
#include <algorithm>

using namespace std;

int arr[50], brr[50];

int main()
{
    int n, m, r;
    cin >> n >> m >> r;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> brr[i];
    }
    sort(arr, arr + n);
    sort(brr, brr + m);
    if (arr[0] >= brr[m - 1])
    {
        cout << r << endl;
    }
    else
    {
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] >= brr[m - 1] || r < arr[i])
            {
                break;
            }
            else
            {
                ans += r / arr[i] * brr[m - 1];
                r %= arr[i];
            }
        }
        cout << r + ans << endl;
    }
    return 0;
}