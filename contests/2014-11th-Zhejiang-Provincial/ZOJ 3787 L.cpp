#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int ans[20007];

struct mys
{
    int time;
    int id;
} arr[20007];

int cmp(const mys &a, const mys &b)
{
    return a.time < b.time;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, l, h, m, s, cnt = 0, tt;
        scanf("%d %d", &n, &l);
        for (int i = 0; i < n; i++)
        {
            scanf("%d:%d:%d", &h, &m, &s);
            arr[i].time = 3600 * h + 60 * m + s;
            arr[i].id = i + 1;
        }
        sort(arr, arr + n, cmp);
        ans[cnt++] = arr[0].id;
        tt = arr[0].time;
        for (int i = 1; i < n; i++)
        {
            if (arr[i].time >= tt + l)
            {
                tt = arr[i].time;
                ans[cnt++] = arr[i].id;
            }
        }
        printf("%d\n", cnt);
        sort(ans, ans + cnt);
        for (int i = 0; i < cnt; i++)
        {
            printf("%d%c", ans[i], " \n"[i == cnt - 1]);
        }
    }
    return 0;
}