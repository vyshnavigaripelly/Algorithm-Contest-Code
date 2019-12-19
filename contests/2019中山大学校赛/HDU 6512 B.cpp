#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[5000007];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        if (n < 100)
        {
            int flag = 0;
            sort(arr, arr + n);
            for (int i = n - 1; i >= 2; i--)
            {
                if (arr[i] < arr[i - 1] + arr[i - 2])
                {
                    flag = 1;
                    break;
                }
            }
            puts(flag ? "YES" : "NO");
        }
        else
        {
            puts("YES");
        }
    }
    return 0;
}