#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

#define lson (root << 1)
#define rson (root << 1 | 1)

const int N = 3e5 + 7;

long long arr[N], tr[N];

inline int lowbit(int x)
{
    return x & (-x);
}

void add(int x, int y)
{
    for (; x <= N; x += lowbit(x))
        tr[x] += y;
}

long long ask(int x)
{
    long long ans = 0;
    for (; x; x -= lowbit(x))
        ans += tr[x];
    return ans;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int op;
        scanf("%d", &op);
        if (op == 1)
        {
            int x;
            scanf("%d", &x);
            long long ans = arr[x];
            int tmp = sqrt(x + 0.5);
            for (int i = 1; i * i <= tmp; i++)
            {
                if (x % i == 0)
                {
                    ans += ask(i);
                    if (x / i != i)
                    {
                        ans += ask(x / i);
                    }
                }
            }
            printf("%lld\n", ans);
        }
        else
        {
            int l, r, x;
            scanf("%d %d %d", &l, &r, &x);
            add(l, x);
            add(r + 1, -x);
        }
    }
    return 0;
}