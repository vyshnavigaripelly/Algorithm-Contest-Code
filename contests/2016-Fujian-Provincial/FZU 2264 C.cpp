#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < 2 * n; i++)
        {
            scanf("%*d");
        }
        printf("Case %d: %.2f\n", cas, n * 0.5);
    }
    return 0;
}