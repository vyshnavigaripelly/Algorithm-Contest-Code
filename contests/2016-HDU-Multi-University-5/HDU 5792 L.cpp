#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 50007;

long long tr[N], arr[N], val[N];
long long ls[N], lb[N], rs[N], rb[N];

inline long long lowbit(long long x)
{
    return x & -x;
}

void add(int pos, long long val)
{
    for (; pos <= N; pos += lowbit(pos))
    {
        tr[pos] += val;
    }
}

long long query(int pos)
{
    long long ans = 0;
    for (; pos; pos -= lowbit(pos))
    {
        ans += tr[pos];
    }
    return ans;
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
            val[i] = arr[i];
        }
        sort(val + 1, val + 1 + n);
        int tot = unique(val + 1, val + 1 + n) - (val + 1);
        for (int i = 1; i <= n; i++)
        {
            arr[i] = lower_bound(val + 1, val + 1 + tot, arr[i]) - (val + 1) + 1;
        }
        // arr - pos, val - val
        memset(tr, 0, sizeof(tr));
        long long sum1 = 0, sum2 = 0;
        for (int i = n; i >= 1; i--)
        {
            rs[i] = query(arr[i] - 1);
            rb[i] = query(tot) - query(arr[i]);
            sum1 += rs[i];
            sum2 += rb[i];
            add(arr[i], 1);
        }
        memset(tr, 0, sizeof(tr));
        for (int i = 1; i <= n; i++)
        {
            ls[i] = query(arr[i] - 1);
            lb[i] = query(tot) - query(arr[i]);
            add(arr[i], 1);
        }
        long long ans = sum1 * sum2;
        for (int i = 1; i <= n; i++)
        {
            ans -= rb[i] * rs[i] + rb[i] * lb[i] +
                   ls[i] * rs[i] + ls[i] * lb[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}