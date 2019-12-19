#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

struct node
{
    int id, x;
} arr1[N], arr2[N], arr3[N];

int n, q, level1[N], level2[N], level3[N], flag[N];

int cmp(node &a, node &b)
{
    return a.x > b.x;
}

int main()
{
    int cnt = 0;
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr1[i].x);
        arr1[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr2[i].x);
        arr2[i].id = i;
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr3[i].x);
        arr3[i].id = i;
    }
    sort(arr1 + 1, arr1 + 1 + n, cmp);
    sort(arr2 + 1, arr2 + 1 + n, cmp);
    sort(arr3 + 1, arr3 + 1 + n, cmp);
    for (int i = 1; i <= n; i++)
    {
        level1[arr1[i].id] = i;
        level2[arr2[i].id] = i;
        level3[arr3[i].id] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr1[i].id == arr2[1].id)
            break;
        if (!flag[arr1[i].id])
        {
            cnt++;
            flag[arr1[i].id] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr1[i].id == arr3[1].id)
            break;
        if (!flag[arr1[i].id])
        {
            cnt++;
            flag[arr1[i].id] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr2[i].id == arr1[1].id)
            break;
        if (!flag[arr2[i].id])
        {
            cnt++;
            flag[arr2[i].id] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr2[i].id == arr3[1].id)
            break;
        if (!flag[arr2[i].id])
        {
            cnt++;
            flag[arr2[i].id] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr3[i].id == arr1[1].id)
            break;
        if (!flag[arr3[i].id])
        {
            cnt++;
            flag[arr3[i].id] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (arr3[i].id == arr2[1].id)
            break;
        if (!flag[arr3[i].id])
        {
            cnt++;
            flag[arr3[i].id] = 1;
        }
    }
    flag[arr1[1].id] = 1;
    flag[arr2[1].id] = 1;
    flag[arr3[1].id] = 1;
    int upper1 = -1, upper2 = -1, upper3 = -1, add = 0;
    do
    {
        add = 0;
        for (int i = n; i >= 1; i--)
        {
            if (flag[arr1[i].id])
            {
                upper1 = i;
                break;
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (flag[arr2[i].id])
            {
                upper2 = i;
                break;
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (flag[arr3[i].id])
            {
                upper3 = i;
                break;
            }
        }
        for (int i = 1; i <= upper1; i++)
        {
            if (!flag[arr1[i].id])
            {
                add++;
                flag[arr1[i].id] = 1;
            }
        }
        for (int i = 1; i <= upper2; i++)
        {
            if (!flag[arr2[i].id])
            {
                add++;
                flag[arr2[i].id] = 1;
            }
        }
        for (int i = 1; i <= upper3; i++)
        {
            if (!flag[arr3[i].id])
            {
                add++;
                flag[arr3[i].id] = 1;
            }
        }
        cnt += add;
    } while (add && cnt != n);
    while (q--)
    {
        int x;
        scanf("%d", &x);
        if (level1[x] <= upper1 || level2[x] <= upper2 || level3[x] <= upper3)
        {
            printf("YES\n");
            continue;
        }
        printf("NO\n");
    }
    return 0;
}