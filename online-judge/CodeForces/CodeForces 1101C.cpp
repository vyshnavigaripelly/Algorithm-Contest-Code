#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
    int l, r, num, id;
} arr[100007];

int cmppos(const Node &a, const Node &b)
{
    if (a.l != b.l)
    {
        return a.l < b.l;
    }
    else
    {
        return a.r < b.r;
    }
}

int cmpnum(const Node &a, const Node &b)
{
    return a.num < b.num;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &arr[i].l, &arr[i].r);
            arr[i].num = i;
        }
        sort(arr + 1, arr + 1 + n, cmppos);
        int maxn = arr[1].r, tmp = -1;
        for (int i = 2; i <= n; i++)
        {
            if (arr[i].l > maxn)
            {
                arr[i].id = 2;
                tmp = i;
            }
            maxn = max(maxn, arr[i].r);
        }
        if (tmp != -1)
        {
            for (int i = 1; i <= n; i++)
            {
                arr[i].id = (tmp > i) ? 1 : 2;
            }
            sort(arr + 1, arr + 1 + n, cmpnum);
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", arr[i].id);
            }
            puts("");
        }
        else
        {
            puts("-1");
        }
    }
    return 0;
}