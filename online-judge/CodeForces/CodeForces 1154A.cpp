#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &arr[i]);
    }
    sort(arr, arr + 4);
    printf("%d %d %d", (arr[2] - arr[1] + arr[0]) / 2, (arr[2] - arr[0] + arr[1]) / 2, arr[0] + arr[1] - arr[3]);
    return 0;
}