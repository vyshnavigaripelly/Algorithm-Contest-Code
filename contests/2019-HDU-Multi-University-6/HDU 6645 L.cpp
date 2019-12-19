#include <algorithm>
#include <iostream>

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
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        long long s = 0, e = 0;
        sort(arr + 1, arr + 1 + n);
        for (int i = n; i >= 1; i--)
        {
            if ((n - i) % 2 == 0)
            {
                s += arr[i];
            }
            else
            {
                e += arr[i];
            }
        }
        printf("%lld %lld\n", s, e);
    }
    return 0;
}