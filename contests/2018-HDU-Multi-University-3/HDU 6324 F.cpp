#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

long long arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            scanf("%*d%*d");
        }
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum ^= arr[i];
        }
        int draw = 0, win = 0;
        for (int i = 0; i < n; i++)
        {
            if (arr[i] > (sum ^ arr[i]))
            {
                win = 1;
            }
            else if (arr[i] == (sum ^ arr[i]))
            {
                draw = 1;
            }
        }
        if (win)
        {
            puts("Q");
        }
        else if (draw)
        {
            puts("D");
        }
        else
        {
            puts("T");
        }
    }
    return 0;
}