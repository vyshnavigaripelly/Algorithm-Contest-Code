#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;
const int N = 1e5 + 7;
long long arr[N];

int main()
{
    arr[0] = arr[1] = arr[2] = 1;
    for (int i = 3; i <= N; i++)
    {
        arr[i] = (arr[i - 1] + arr[i - 3]) % MOD;
    }
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int q, n, m;
        scanf("%d %d %d", &q, &n, &m);
        if (n > m)
            swap(n, m);
        int ans = abs(n - m);
        if (n == 1 && m == q)
        {
            printf("%lld\n", arr[ans]);
        }
        else if (n == 1 || m == q)
        {
            ans--;
            printf("%lld\n", arr[ans]);
            continue;
        }
        else
        {
            ans -= 2;
            printf("%lld\n", arr[ans]);
        }
    }
    return 0;
}