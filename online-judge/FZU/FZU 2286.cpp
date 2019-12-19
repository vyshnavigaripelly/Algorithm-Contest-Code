#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

struct Node
{
    int x, y, v;
} mon[112345];

double distsqr(Node &mon, int &y)
{
    return (mon.x - 0) * (mon.x - 0) + (mon.y - y) * (mon.y - y);
}

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(mon, 0, sizeof(mon));
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &mon[i].x, &mon[i].y, &mon[i].v);
        }
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            for (int t = 0; t <= 100; t++)
            {
                if (distsqr(mon[i], t) <= mon[i].v * mon[i].v * t * t)
                {
                    cnt++;
                    break;
                }
            }
        }
        printf("%d\n", cnt);
    }
    return 0;
}
