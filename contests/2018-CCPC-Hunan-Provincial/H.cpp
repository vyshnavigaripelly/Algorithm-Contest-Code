#include <iostream>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

struct BIT
{
#define lowbit(x) (x & (-x))

    int c[N];

    void init()
    {
        memset(c, 0, sizeof(c));
    }

    void add(int pos, int val)
    {
        while (pos < N)
        {
            c[pos] += val;
            pos += lowbit(pos);
        }
    }

    int query(int l, int r)
    {
        return l > r ? 0 : presum(r) - presum(l - 1);
    }

    int presum(int pos)
    {
        int ans = 0;
        while (pos > 0)
        {
            ans += c[pos];
            pos -= lowbit(pos);
        }
        return ans;
    }

#undef lowbit
} lef, righ;

int main()
{
    int n, m;
    while (~scanf("%d %d", &n, &m))
    {
        lef.init();
        righ.init();
        int cnt = 0;
        while (m--)
        {
            int op, l, r;
            scanf("%d %d %d", &op, &l, &r);
            if (op == 1)
            {
                cnt++;
                lef.add(l, 1);
                righ.add(r, 1);
            }
            else
            {
                int ans = cnt;
                ans -= lef.query(l + 1, n);
                ans -= righ.query(1, r - 1);
                printf("%d\n", ans);
            }
        }
    }
    return 0;
}