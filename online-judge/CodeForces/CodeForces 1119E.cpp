#include <iostream>
#include <algorithm>

using namespace std;

long long arr[300007], cnt, ans;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 1; i <= n; i++)
    {
        long long tmp = min(arr[i] / 2, cnt);
        cnt -= tmp;
        arr[i] -= 2LL * tmp;
        ans += tmp + arr[i] / 3;
        arr[i] %= 3;
        cnt += arr[i];
    }
    cout << ans << endl;
    return 0;
}