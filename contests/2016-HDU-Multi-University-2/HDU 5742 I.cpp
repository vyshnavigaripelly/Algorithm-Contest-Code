#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

long long arr[107];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(arr, -1, sizeof(arr));
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int x, y;
            scanf("%d %d", &x, &y);
            arr[x] = y;
        }
        arr[n + 1] = 0;
        for (int i = n; i >= 3; i--)
        {
            if (arr[i] != -1)
                continue;
            arr[i] = arr[i + 1];
        }
        if (arr[1] == -1 && arr[2] == -1)
        {
            arr[1] = arr[2] = 100;
        }
        else if (arr[1] == -1)
        {
            arr[1] = 100;
        }
        else if (arr[2] == -1)
        {
            arr[2] = arr[1];
        }
        long long sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum += arr[i];
        }
        long long g = __gcd(arr[1] + arr[2], sum);
        printf("%lld/%lld\n", (arr[1] + arr[2]) / g, sum / g);
    }
    return 0;
}