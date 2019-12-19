#include <iostream>
#include <algorithm>
using namespace std;

int arr[233333];

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr + 1, arr + 1 + n);
    if (arr[k] == arr[k + 1] || (k == 0 && arr[1] == 1))
    {
        printf("-1\n");
    }
    else
    {
        if (k == 0)
        {
            printf("1\n");
        }
        else
        {
            printf("%d\n", arr[k]);
        }
    }
    return 0;
}
