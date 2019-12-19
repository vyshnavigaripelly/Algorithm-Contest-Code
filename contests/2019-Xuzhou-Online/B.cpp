#include <iostream>
#include <unordered_map>
#include <cstring>

using namespace std;

unordered_map<int, int> rk, dfn;
int cnt, bcj[1000007];

int Find(int x)
{
    if (bcj[x] < 0)
        return x;
    return bcj[x] = Find(bcj[x]);
}

int main()
{
    memset(bcj, -1, sizeof(bcj));
    int n, q;
    scanf("%d%d", &n, &q);
    while (q--)
    {
        int opt, v;
        scanf("%d%d", &opt, &v);
        if (opt == 1)
        {
            if (rk.count(v))
                continue;
            rk[v] = ++cnt;
            dfn[cnt] = v;
            if (rk.count(v - 1))
            {
                int x = Find(rk[v]), y = Find(rk[v - 1]);
                bcj[y] += bcj[x];
                bcj[x] = y;
            }
            if (rk.count(v + 1))
            {
                int x = Find(rk[v]), y = Find(rk[v + 1]);
                bcj[x] += bcj[y];
                bcj[y] = x;
            }
        }
        else
        {
            if (!rk.count(v))
            {
                printf("%d\n", v);
            }
            else
            {
                int rt = Find(rk[v]);
                int s = -bcj[rt];
                if (dfn[rt] + s > n)
                    printf("-1\n");
                else
                    printf("%d\n", dfn[rt] + s);
            }
        }
    }
    return 0;
}
