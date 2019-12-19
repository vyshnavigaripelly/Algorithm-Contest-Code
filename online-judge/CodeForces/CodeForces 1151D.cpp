#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Node
{
    long long a, b, sum;
} arr[1000007];

int main()
{
    long long n;
    scanf("%lld", &n);
    for (long long i = 0; i < n; i++)
    {
        scanf("%lld %lld", &arr[i].a, &arr[i].b);
        arr[i].sum = arr[i].a - arr[i].b;
    }
    sort(arr, arr + n, [](const Node &a, const Node &b) {
        return a.sum > b.sum;
    });
    for (long long i = 0; i < n - 1; i++)
    {
        if (arr[i].sum == arr[i + 1].sum)
        {
            long long tmp1 = arr[i].a * i + arr[i].b * (n - 1 - i) + arr[i + 1].a * (i + 1) + arr[i + 1].b * (n - i - 2);
            long long tmp2 = arr[i + 1].a * i + arr[i + 1].b * (n - i - 1) + arr[i].a * (i + 1) + arr[i].b * (n - i - 2);
            if (tmp1 > tmp2)
            {
                swap(arr[i], arr[i + 1]);
            }
        }
    }
    long long ans = 0;
    for (long long i = 0; i < n; i++)
    {
        ans = ans + arr[i].a * i + arr[i].b * (n - 1 - i);
    }
    printf("%lld\n", ans);
    return 0;
}