#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int ans = 1;
    while (n > 3)
    {
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            printf("%d ", ans);
        }
        n /= 2;
        ans *= 2;
    }
    if (n == 3)
    {
        printf("%d %d %d", ans, ans, ans * 3);
    }
    else if (n == 2)
    {
        printf("%d %d", ans, ans * 2);
    }
    else if (n == 1)
    {
        printf("%d", ans);
    }
    return 0;
}
