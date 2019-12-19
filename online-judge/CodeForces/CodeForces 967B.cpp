#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[100010];

int main()
{
    int n, a, b, sum = 0;
    cin >> n >> a >> b;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    sort(arr + 1, arr + n, greater<int>());
    arr[0] = sum;
    arr[1] = sum - arr[1];
    for (int i = 2; i < n; i++)
    {
        arr[i] = arr[i - 1] - arr[i];
    }
    int ll = 0, rr = n - 1, mid; // number of holes blocked
    while (ll < rr)
    {
        mid = (ll + rr) / 2;
        if (1.0 * a * arr[n - 1] / arr[mid] < b)
        {
            ll = mid + 1;
        }
        else
        {
            rr = mid;
        }
    }
    cout << rr << endl;
    return 0;
}
