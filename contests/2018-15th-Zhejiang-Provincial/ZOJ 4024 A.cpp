#include <iostream>
#include <cstdio>
using namespace std;

const int maxn = 1e5 + 5;

int arr[maxn];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, max = 0, maxpos = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] > max)
            {
                max = arr[i];
                maxpos = i;
            }
        }
        int flag1 = 0, flag2 = 0;
        for (int i = 1; i <= maxpos; i++)
        {
            if (arr[i] <= arr[i - 1])
            {
                flag1 = 1;
                break;
            }
        }
        for (int i = maxpos + 1; i < n; i++)
        {
            if (arr[i] >= arr[i - 1])
            {
                flag2 = 1;
                break;
            }
        }
        if (!flag1 && !flag2 && maxpos != 0 && maxpos != n - 1)
        {
            printf("Yes\n");
        }
        else
        {
            printf("No\n");
        }
    }
    return 0;
}
