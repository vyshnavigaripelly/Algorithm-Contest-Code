#include <iostream>
#include <algorithm>
using namespace std;

int arr[107];

int main()
{
    int n;
    cin >> n;
    int sum = 0, minn = 999, maxn = 0, sum2 = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum += arr[i];
        minn = min(minn, arr[i]);
        maxn = max(maxn, arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sum2 += maxn - arr[i];
    }
    while (sum2 <= sum)
    {
        sum2 += n;
    }
    cout << (sum + sum2) / n << endl;
    return 0;
}