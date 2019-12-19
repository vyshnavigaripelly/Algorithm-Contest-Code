#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 1e5 + 7;

int arr[N], num[N], lis[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        memset(lis, 0, sizeof(lis));
        memset(num, 0, sizeof(num));
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int cnt = 0, zero = 0, len = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                zero++;
                continue;
            }
            num[cnt++] = arr[i] - zero;
        }
        if (cnt == 0)
        {
            len = -1;
        }
        else
        {
            lis[0] = num[0];
            for (int i = 1; i < cnt; i++)
            {
                if (num[i] > lis[len])
                {
                    lis[++len] = num[i];
                }
                else
                {
                    int pos = upper_bound(lis, lis + len, num[i]) - lis;
                    lis[pos] = num[i];
                }
            }
        }
        printf("Case #%d: %d\n", cas, len + 1 + zero);
    }
    return 0;
}