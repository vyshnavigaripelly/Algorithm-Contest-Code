#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

struct mys
{
    long long a, b;
} arr[200100];

int cmp(const mys &a, const mys &b)
{
    return a.a * b.b < b.a * a.b;
}

int main()
{
    long long mod = 365 * 24 * 60 * 60;
    int n;
    while (cin >> n && n)
    {
        long long time = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld%lld", &arr[i].a, &arr[i].b);
        }
        sort(arr, arr + n, cmp);
        for (int i = 0; i < n; i++)
        {
            if (arr[i].a)
            {
                ans = (ans + (arr[i].a + time * arr[i].b) % mod) % mod;
                time = (time + (arr[i].a + time * arr[i].b) % mod) % mod;
            }
        }
        printf("%lld\n", ans % mod);
    }
    return 0;
}