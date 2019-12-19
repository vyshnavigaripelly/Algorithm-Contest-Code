#include <bits/stdc++.h>

using namespace std;

const int N = 100007;

long long arr[N];
long long odd[N], even[N];

void addeven(int pos, long long val)
{
    for (; pos <= N; pos += (pos & -pos))
        even[pos] ^= val;
}

void addodd(int pos, long long val)
{
    for (; pos <= N; pos += (pos & -pos))
        odd[pos] ^= val;
}

long long askeven(int pos)
{
    long long ans = 0;
    for (; pos; pos -= (pos & -pos))
        ans ^= even[pos];
    return ans;
}

long long askodd(int pos)
{
    long long ans = 0;
    for (; pos; pos -= (pos & -pos))
        ans ^= odd[pos];
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(odd, 0, sizeof(odd));
        memset(even, 0, sizeof(even));
        long long n, m;
        scanf("%lld %lld", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 1)
                addodd((i + 1) / 2, arr[i]);
            else
                addeven(i / 2, arr[i]);
        }
        printf("Case #%d:\n", cas);
        for (int i = 0; i < m; i++)
        {
            int op;
            scanf("%d", &op);
            if (op == 0)
            {
                int x;
                long long y;
                scanf("%d %lld", &x, &y);
                if (x % 2 == 1)
                {
                    addodd((x + 1) / 2, arr[x]);
                    addodd((x + 1) / 2, y);
                }
                else
                {
                    addeven(x / 2, arr[x]);
                    addeven(x / 2, y);
                }
                arr[x] = y;
            }
            else
            {
                int l, r;
                scanf("%d %d", &l, &r);
                long long ans;
                if ((r - l + 1) % 2 == 0)
                {
                    ans = 0;
                }
                else
                {
                    if (l % 2 == 1)
                    {
                        ans = askodd((r + 1) / 2) ^ askodd((l + 1) / 2 - 1);
                    }
                    else
                    {
                        ans = askeven(r / 2) ^ askeven(l / 2 - 1);
                    }
                }
                printf("%lld\n", ans);
            }
        }
    }
    return 0;
}