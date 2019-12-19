#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100007], brr[100007];

int main()
{
    long long n, m, k;
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n - 1; i++)
    {
        brr[i] = arr[i + 1] - arr[i] - 1;
    }
    sort(brr, brr + n - 1);
    long long ans = n;
    for (int i = 0; i < n - k; i++)
    {
        ans += brr[i];
    }
    cout << ans << endl;
    return 0;
}