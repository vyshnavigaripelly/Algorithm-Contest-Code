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
    int flag = true;
    if (arr[n - 1] >= arr[n - 2] + arr[0])
    {
        for (int i = n - 1; i >= 1; i--)
        {
            if (arr[i] != arr[n - 1])
            {
                if (arr[i] < arr[n - 2] + arr[0] && arr[n - 1] < arr[i - 1] + arr[i + 1])
                {
                    swap(arr[i], arr[n - 1]);
                    break;
                }
            }
        }
    }
    for (int i = 1; i < n - 1; i++)
    {
        if (arr[i] >= arr[i - 1] + arr[i + 1])
        {
            flag = 0;
            break;
        }
    }
    if (flag)
    {
        cout << "YES" << endl;
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << ' ';
        }
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}