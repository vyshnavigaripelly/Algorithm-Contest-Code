#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int arr[100007], arr1[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int cnt = n - 1, pos = n - 1;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            arr1[i] = arr[i];
        }
        sort(arr1, arr1 + n);
        while (pos >= 0)
        {
            if (arr[pos] == arr1[cnt])
            {
                pos--;
                cnt--;
            }
            else
            {
                pos--;
            }
        }
        printf("%d\n", cnt + 1);
    }
    return 0;
}
