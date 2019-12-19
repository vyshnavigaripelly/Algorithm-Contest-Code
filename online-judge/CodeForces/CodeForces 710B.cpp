#include <iostream>
#include <algorithm>

using namespace std;

int arr[300007];

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    if (n % 2 == 1)
    {
        cout << arr[n / 2] << endl;
    }
    else
    {
        cout << arr[n / 2 - 1] << endl;
    }
    return 0;
}