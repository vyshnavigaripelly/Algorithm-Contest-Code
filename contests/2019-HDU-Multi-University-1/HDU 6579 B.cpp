#include <bits/stdc++.h>

using namespace std;

struct LinearBasis
{
    static const int Maxn = 1e6 + 7;
    static const int Maxd = 31;
    int cnt;
    int sum[Maxn][Maxd + 7];
    int pos[Maxn][Maxd + 7];

    void init()
    {
        cnt = 0;
    }

    void add(int x)
    {
        int pos_x = ++cnt;
        for (int i = Maxd; i >= 0; i--)
        {
            sum[cnt][i] = sum[cnt - 1][i];
            pos[cnt][i] = pos[cnt - 1][i];
        }
        for (int i = Maxd; i >= 0; i--)
        {
            if (x >> i)
            {
                if (!sum[cnt][i])
                {
                    sum[cnt][i] = x;
                    pos[cnt][i] = pos_x;
                    break;
                }
                else
                {
                    if (pos_x > pos[cnt][i])
                    {
                        swap(sum[cnt][i], x);
                        swap(pos[cnt][i], pos_x);
                    }
                    x ^= sum[cnt][i];
                }
            }
        }
    }

    int query(int l, int r)
    {
        l = l % cnt + 1;
        r = r % cnt + 1;
        if (l > r)
            swap(l, r);
        int res = 0;
        for (int i = Maxd; i >= 0; i--)
        {
            if (pos[r][i] >= l)
                res = max(res, res ^ sum[r][i]);
        }
        return res;
    }
};

LinearBasis lb;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        lb.init();
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            lb.add(tmp);
        }
        int lastans = 0, opt, x, y;
        for (int i = 0; i < m; i++)
        {
            scanf("%d%d", &opt, &x);
            if (opt == 0)
            {
                scanf("%d", &y);
                printf("%d\n", lastans = lb.query(x ^ lastans, y ^ lastans));
            }
            else
            {
                lb.add(x ^ lastans);
            }
        }
    }
    return 0;
}
