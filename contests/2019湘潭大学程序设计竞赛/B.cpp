#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int ans = 0;
        while (n > 1)
        {
            if (n % 10 == 0)
                n /= 10;
            else
                n++;
            ans++;
        }
        printf("%d\n", ans);
    }
    return 0;
}