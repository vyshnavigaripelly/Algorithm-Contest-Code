#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            int tmp;
            scanf("%d", &tmp);
            ans += tmp + (tmp + 9) / 10;
        }
        printf("Case #%d: %lld\n", cas, ans);
    }
    return 0;
}