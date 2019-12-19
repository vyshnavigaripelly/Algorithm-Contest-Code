#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
using namespace std;

const int MAXN = 100005;

int odd[MAXN], even[MAXN];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(odd, 0x3f, sizeof(odd));
        memset(even, 0x3f, sizeof(even));
        int on = 0, en = 0;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                scanf("%d", &even[en++]);
            }
            else
            {
                scanf("%d", &odd[on++]);
            }
        }
        sort(even, even + en);
        sort(odd, odd + on);
        int flag = 1;
        for (int i = 1; i <= n; i++)
        {
            if (i % 2 == 0)
            {
                if (even[i / 2 - 1] > odd[i / 2])
                {
                    printf("%d\n", i);
                    flag = 0;
                    break;
                }
            }
            else
            {
                if (odd[i / 2] > even[i / 2])
                {
                    printf("%d\n", i);
                    flag = 0;
                    break;
                }
            }
        }
        if (flag)
        {
            printf("OK\n");
        }
    }
    return 0;
}
