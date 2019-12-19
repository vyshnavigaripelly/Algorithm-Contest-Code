#include <iostream>
#include <algorithm>

using namespace std;

long long arr[100007], sum[100007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    sort(arr + 1, arr + 1 + n);
    for (int i = n; i >= 1; i--)
    {
        arr[i] = arr[i] - arr[i - 1];
    }
    arr[1] = 0;
    sort(arr + 1, arr + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + arr[i];
    }
    int q;
    cin >> q;
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        long long len = r - l + 1;
        long long pos = upper_bound(arr + 1, arr + 1 + n, len) - arr - 1;
        long long ans = 0;
        long long tmp1 = (n - pos) * len;
        long long tmp2 = sum[pos] + len;
        cout << tmp1 + tmp2 << ' ';
    }
    return 0;
}