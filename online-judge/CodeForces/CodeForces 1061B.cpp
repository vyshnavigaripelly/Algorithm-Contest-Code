#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

long long arr[100007];

int main()
{
    long long n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n);
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > ans)
        {
            ans++;
        }
    }
    ans = n - 1 + arr[n - 1] - ans + 1;
    cout << accumulate(arr, arr + n, 0LL) - ans << endl;
    return 0;
}