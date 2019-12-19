#include <iostream>
#include <algorithm>

using namespace std;

long long arr[400007];

int main()
{
    int n;
    long long ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = 1, j = n; i <= n / 2; i++, j--)
    {
        ans += (arr[i] + arr[j]) * (arr[i] + arr[j]);
    }
    cout << ans << endl;
    return 0;
}