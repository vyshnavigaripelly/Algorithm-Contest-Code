#include <iostream>
#include <algorithm>

using namespace std;

long long sum[200007], arr[200007], minn = 0x7fffffff;

int main()
{
    long long h, n;
    cin >> h >> n;
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        sum[i] = sum[i - 1] + arr[i];
        minn = min(minn, sum[i]);
        if (h + sum[i] <= 0)
        {
            cout << i << endl;
            return 0;
        }
    }
    if (minn >= 0 || sum[n] >= 0)
    {
        cout << -1 << endl;
        return 0;
    }
    long long cnt = max(1LL, ((h + minn) / -sum[n])) * n, tmp = 0;
    long long res = h + (cnt / n) * sum[n];
    while (res > 0)
    {
        tmp++;
        res += arr[tmp % n == 0 ? n : tmp % n];
    }
    cout << cnt + tmp << endl;
    return 0;
}