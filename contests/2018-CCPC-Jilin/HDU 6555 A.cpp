#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdio>

using namespace std;

long long sqr[100007];

int main()
{
    int tot;
    for (tot = 1; tot * tot <= 2e9; tot++)
    {
        sqr[tot] = tot * tot;
    }
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        int pos = lower_bound(sqr + 1, sqr + 1 + tot, n + 1) - (sqr + 1);
        printf("Case %d: %s\n", cas, pos % 2 == 1 ? "odd" : "even");
    }
    return 0;
}