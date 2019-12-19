#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int arr[123], cut[123], cnt = 0;

int main()
{
    int n, b, even = 0, odd = 0;
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (even == odd && even != 0)
        {
            cut[cnt++] = abs(arr[i] - arr[i - 1]);
        }
        if (arr[i] % 2 == 0)
        {
            odd++;
        }
        else
        {
            even++;
        }
    }
    sort(cut, cut + cnt);
    int cost = 0, ans = 0;
    for (int i = 0; i < cnt; i++)
    {
        cost += cut[i];
        ans++;
        if (cost > b)
        {
            ans--;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}