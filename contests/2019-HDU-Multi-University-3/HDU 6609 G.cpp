#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

multiset<long long, greater<long long>> se;
long long arr[200007], ans[200007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        se.clear();
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &arr[i]);
        }
        long long sum = arr[1];
        se.insert(arr[1]);
        int popcnt = 0;
        for (int i = 2; i <= n; i++)
        {
            long long tmp = sum + arr[i];
            auto it = se.begin();
            int cnt = 0;
            while (tmp > m)
            {
                cnt++;
                tmp -= *it;
                it++;
            }
            ans[i] = cnt + popcnt;
            se.insert(arr[i]);
            sum += arr[i];
            while (sum > m)
            {
                popcnt++;
                sum -= *se.begin();
                se.erase(se.begin());
            }
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%lld ", ans[i]);
        }
        puts("");
    }
    return 0;
}