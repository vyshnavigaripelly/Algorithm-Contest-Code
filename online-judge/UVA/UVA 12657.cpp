#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int MAXN = 100010;

int leftb[MAXN], rightb[MAXN];

void connect(int x, int y)
{
    leftb[y] = x;
    rightb[x] = y;
}

int main()
{
    int n, m, cas = 1;
    while (~scanf("%d %d", &n, &m))
    {
        memset(leftb, 0, sizeof(leftb));
        memset(rightb, 0, sizeof(rightb));
        for (int i = 1; i <= n; i++)
        {
            leftb[i] = i - 1;
            rightb[i] = i + 1;
        }
        rightb[n] = 0;
        rightb[0] = 1;
        leftb[0] = n;
        int rev = 0;
        while (m--)
        {
            int op, x, y;
            scanf("%d", &op);
            if (op == 4)
            {
                rev = !rev;
            }
            else
            {
                scanf("%d %d", &x, &y);
                int Lx = leftb[x], Rx = rightb[x], Ly = leftb[y], Ry = rightb[y];
                if ((op == 1 && !rev) || (op == 2 && rev))
                {
                    if (Ly == x)
                    {
                        continue;
                    }
                    connect(Lx, Rx);
                    connect(Ly, x);
                    connect(x, y);
                }
                else if ((op == 2 && !rev) || (op == 1 && rev))
                {
                    if (Ry == x)
                    {
                        continue;
                    }
                    connect(Lx, Rx);
                    connect(y, x);
                    connect(x, Ry);
                }
                else if (op == 3)
                {
                    if (rightb[x] == y) // ...-x-y-...
                    {
                        connect(Lx, y);
                        connect(y, x);
                        connect(x, Ry);
                    }
                    else if (rightb[y] == x) // ...-y-x-...
                    {
                        connect(Ly, x);
                        connect(x, y);
                        connect(y, Rx);
                    }
                    else // ...-x-...-y-... or ...-y-...-x-...
                    {
                        connect(Lx, y);
                        connect(y, Rx);
                        connect(Ly, x);
                        connect(x, Ry);
                    }
                }
            }
        }
        int cur = 0;
        long long s = 0;
        if (rev)
        {
            for (int i = n; i >= 1; i--)
            {
                cur = leftb[cur];
                if ((n - i + 1) % 2 == 1)
                {
                    s += cur;
                }
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
            {
                cur = rightb[cur];
                if (i % 2 == 1)
                {
                    s += cur;
                }
            }
        }
        printf("Case %d: %lld\n", cas, s);
        cas++;
    }
    return 0;
}
