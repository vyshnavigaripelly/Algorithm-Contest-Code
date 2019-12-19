#include <iostream>
#include <cstdio>

using namespace std;

int arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            cnt += (arr[i] & 1);
        }
        if (cnt > n - cnt)
        {
            printf("2 1\n");
        }
        else
        {
            printf("2 0\n");
        }
    }
    return 0;
}