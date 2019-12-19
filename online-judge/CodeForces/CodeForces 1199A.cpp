#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100007];

int main()
{
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    int flag = 0;
    for (int i = 1; i <= n && !flag; i++)
    {
        int l = max(1, i - x), r = min(n, i + y);
        for (int j = l; j <= r && !flag; j++)
        {
            if (arr[j] < arr[i])
            {
                break;
            }
            if (j == r)
            {
                printf("%d\n", i);
                flag = 1;
            }
        }
    }
    return 0;
}