#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 5;

long long tim[N], arr[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, k;
        scanf("%lld %lld", &n, &k);
        long long cnt = 0, sum = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", tim + i);
            cnt += tim[i] / k;
            long long tmp = tim[i] % k;
            if (tmp > 0)
            {
                arr[len++] = tmp;
                sum += tmp;
            }
        }
        long long ans = k + cnt * k;
        if (cnt < n - 1)
        {
            sort(arr, arr + len, greater<long long>());
            long long num = n - 1 - cnt;
            ans += num * k;
            for (int i = num; i < len; i++)
            {
                ans += arr[i];
            }
        }
        else
        {
            ans += sum;
        }
        printf("%lld\n", ans);
    }
    return 0;
}