#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

int arr[N], ans[N];

struct BIT
{
    int c[N];

    void init()
    {
        memset(c, 0, sizeof(c));
    }

    void add(int pos, int val)
    {
        for (; pos <= N; pos += pos & -pos)
            c[pos] += val;
    }

    int query(int pos)
    {
        int ans = 0;
        for (; pos > 0; pos -= pos & -pos)
            ans += c[pos];
        return ans;
    }
} bit;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        bit.init();
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = n; i >= 1; i--)
        {
            bit.add(arr[i], 1);
            ans[arr[i]] = i + bit.query(arr[i] - 1) - min(i, arr[i]);
        }
        printf("Case #%d:", cas);
        for (int i = 1; i <= n; i++)
        {
            printf(" %d", ans[i]);
        }
        puts("");
    }
    return 0;
}