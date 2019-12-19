#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct node
{
    long long x, y, flag;
} arr[100007];

int main()
{
    int t;
    while (~scanf("%d", &t) && t)
    {
        long long cnt = 0;
        while (t--)
        {
            long long op, x, y;
            scanf("%lld %lld %lld", &op, &x, &y);
            if (op == 1)
            {
                arr[cnt].x = x;
                arr[cnt].y = y;
                arr[cnt].flag = 1;
                cnt++;
            }
            else if (op == -1)
            {
                for (int i = 0; i < cnt; i++)
                {
                    if (arr[i].x == x && arr[i].y == y && arr[i].flag == 1)
                    {
                        arr[i].flag = 0;
                        break;
                    }
                }
            }
            else
            {
                long long ans = -0x3f3f3f3f3f3f3f3f;
                for (int i = 0; i < cnt; i++)
                {
                    if (arr[i].flag)
                    {
                        ans = max(x * arr[i].x + y * arr[i].y, ans);
                    }
                }
                printf("%lld\n", ans);
            }
        }
    }
}