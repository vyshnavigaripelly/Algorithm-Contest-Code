#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int arr[107][107][107];

int main()
{
    int x, y, z;
    while (~scanf("%d %d %d", &x, &y, &z))
    {
        memset(arr, 0, sizeof(arr));
        int t;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                scanf("%d", &t);
                if (t == 1)
                {
                    for (int k = 0; k < z; k++)
                    {
                        arr[i][j][k]++;
                    }
                }
            }
        }
        for (int j = 0; j < y; j++)
        {
            for (int k = 0; k < z; k++)
            {
                scanf("%d", &t);
                if (t == 1)
                {
                    for (int i = 0; i < x; i++)
                    {
                        arr[i][j][k]++;
                    }
                }
            }
        }
        for (int k = 0; k < z; k++)
        {
            for (int i = 0; i < x; i++)
            {
                scanf("%d", &t);
                if (t == 1)
                {
                    for (int j = 0; j < y; j++)
                    {
                        arr[i][j][k]++;
                    }
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++)
            {
                for (int k = 0; k < z; k++)
                {
                    if (arr[i][j][k] == 3)
                    {
                        ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}