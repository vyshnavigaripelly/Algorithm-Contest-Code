#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;

int arr[107], sum[107];

int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < m; i++)
    {
        int l, r;
        cin >> l >> r;
        sum[i] = accumulate(arr + l, arr + r + 1, 0);
    }
    sort(sum, sum + m, greater<int>());
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        if (sum[i] < 0)
        {
            break;
        }
        else
        {
            ans += sum[i];
        }
    }
    cout << ans << endl;
    return 0;
}