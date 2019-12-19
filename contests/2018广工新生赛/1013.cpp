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
        while (n != 1)
        {
            if (n % 2 == 1)
            {
                printf("%d*3+1=%d\n", n, n * 3 + 1);
                n = n * 3 + 1;
            }
            else
            {
                printf("%d/2=%d\n", n, n / 2);
                n = n / 2;
            }
        }
        if (t > 0)
        {
            puts("");
        }
    }
    return 0;
}