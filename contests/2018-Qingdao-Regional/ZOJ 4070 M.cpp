#include <iostream>
#include <cstdio>
using namespace std;

int arr[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

int ans[100007];

int solve(int n)
{
    int x = 0;
    if (n == 0)
    {
        return 1;
    }
    while (n)
    {
        x += arr[n % 10];
        n /= 10;
    }
    return x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k, i;
        scanf("%d %d", &n, &k);
        if (k == 0)
        {
            printf("%d\n", n);
            continue;
        }
        for (i = 0; i < k; i++)
        {
            n = solve(n);
            ans[i] = n;
            if (ans[i] == 0 && ans[i - 1] == 1)
            {
                break;
            }
        }
        if (i == k)
        {
            printf("%d\n", ans[k - 1]);
        }
        else
        {
            if ((k - i) % 2 == 0)
            {
                puts("1");
            }
            else
            {
                puts("0");
            }
        }
    }
    return 0;
}