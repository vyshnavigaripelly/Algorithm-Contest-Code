#include <iostream>
#include <algorithm>
using namespace std;

int arr[105];

int main()
{
    int n, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    sort(arr, arr + n);
    int cnt = 0;
    while (sum < 4.5 * n)
    {
        sum += 5 - arr[cnt];
        cnt++;
    }
    cout << cnt << endl;
    return 0;
}