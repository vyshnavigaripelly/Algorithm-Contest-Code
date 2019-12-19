#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int N = 1e5 + 7;
ll arr[N], brr[N], crr[N];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n, ans = 0, sum = 0;
        scanf("%lld", &n);
        arr[1] = 0;
        for (int i = 1; i < n; i++)
        {
            scanf("%lld", &arr[i]);
            sum += arr[i];
        }
        ll sum_tmp = 0, l = 1, r = n - 1;
        for (int i = 1; i <= n; i++)
        {
            int pos = i / 2;
            if (i & 1)
            {
                ans += sum_tmp;
            }
            else
            {
                sum_tmp += sum;
                sum -= arr[l] + arr[r];
                l++, r--;
                ans += sum_tmp;
            }
            printf("%lld%c", ans, " \n"[i == n]);
        }
    }
    return 0;
}