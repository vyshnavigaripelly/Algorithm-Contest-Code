#include <iostream>
#include <set>
#include <cstdio>

using namespace std;

set<long long> se;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        se.clear();
        int n;
        scanf("%d", &n);
        while (n--)
        {
            long long k;
            scanf("%lld", &k);
            se.insert(k);
        }
        long long ans = 0;
        while (se.size() > 1)
        {
            auto tmp1 = se.begin(), tmp2 = --se.end();
            ans += *tmp1;
            long long tmp = *tmp1 + *tmp2;
            se.erase(tmp1);
            se.erase(tmp2);
            se.insert(tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}