#include <iostream>
#include <algorithm>

using namespace std;

long long arr[200007];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, greater<long long>());
    if (arr[0] == arr[1])
    {
        cout << arr[0] * m << endl;
    }
    else
    {
        cout << (arr[0] * k + arr[1]) * (m / (k + 1)) + arr[0] * (m % (k + 1)) << endl;
    }
    return 0;
}