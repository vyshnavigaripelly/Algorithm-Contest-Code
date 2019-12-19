#include <bits/stdc++.h>

using namespace std;

const int N = 1e6 + 7;

int arr[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        memset(arr, 0, sizeof(arr));
        int q, num = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &q);
            arr[q]++;
        }
        for (int i = 1; i < N; i++)
        {
            if (i >= 3)
            {
                if (arr[i] && arr[i - 1] && arr[i - 2])
                {
                    arr[i]--, arr[i - 1]--, arr[i - 2]--;
                    num++;
                }
            }
            num += arr[i] / 2;
            arr[i] %= 2;
        }
        printf("%d\n", num);
    }
    return 0;
}
