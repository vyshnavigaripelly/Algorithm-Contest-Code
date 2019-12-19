#include <iostream>
#include <algorithm>
using namespace std;

int arr[3];

int main()
{
    for (int &k : arr)
    {
        cin >> k;
    }
    sort(arr, arr + 3);
    if (arr[2] >= arr[0] + arr[1])
    {
        cout << arr[2] - arr[1] - arr[0] + 1 << endl;
    }
    else
    {
        cout << 0 << endl;
    }
    return 0;
}