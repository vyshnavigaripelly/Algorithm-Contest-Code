#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

const int N = 1e3 + 7;

int c[N][N];

int query(int x, int y)
{
    int ans = 0;
    for (int i = x; i; i -= i & -i)
        for (int j = y; j; j -= j & -j)
            ans += c[i][j];
    return ans;
}

void add(int x, int y, int val)
{
    for (int i = x; i <= N; i += i & -i)
        for (int j = y; j <= N; j += j & -j)
            c[i][j] += val;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        scanf("%d %d", &n, &q);
        memset(c, 0, sizeof(c));
        while (q--)
        {
            char op[2];
            int x1, y1, x2, y2;
            scanf("%s", op);
            if (op[0] == 'C')
            {
                scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
                add(x1, y1, 1);
                add(x1, y2 + 1, -1);
                add(x2 + 1, y1, -1);
                add(x2 + 1, y2 + 1, 1);
            }
            else
            {
                scanf("%d %d", &x1, &y1);
                printf("%d\n", query(x1, y1) % 2);
            }
        }
        puts("");
    }
    return 0;
}