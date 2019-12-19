#include <iostream>
#include <algorithm>

using namespace std;

int arr[107];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    int tot = unique(arr, arr + n) - arr;
    if (tot > 3)
    {
        cout << -1 << endl;
    }
    else if (tot == 3)
    {
        if (arr[2] - arr[1] == arr[1] - arr[0])
        {
            cout << arr[1] - arr[0] << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
    else if (tot == 2)
    {
        if ((arr[1] - arr[0]) % 2 == 0)
        {
            cout << (arr[1] - arr[0]) / 2 << endl;
        }
        else
        {
            cout << arr[1] - arr[0] << endl;
        }
    }
    else if (tot == 1)
    {
        cout << 0 << endl;
    }
    return 0;
}