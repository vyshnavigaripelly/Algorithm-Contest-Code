#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[107];

int main()
{
    int n, t;
    scanf("%d %d", &n, &t);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &arr[i]);
    }
    sort(arr, arr + n);
    arr[n] = 1e4;
    long long now = 0, cnt = 0;
    for (int i = 0; i < n + 1; i++)
    {
        now += arr[i];
        cnt++;
        if (now > t)
        {
            break;
        }
    }
    printf("%lld\n", cnt - 1);
    return 0;
}