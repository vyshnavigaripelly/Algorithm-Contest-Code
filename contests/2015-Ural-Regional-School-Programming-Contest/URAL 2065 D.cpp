#include <iostream>

using namespace std;

int main()
{
    int n, k;
    scanf("%d%d", &n, &k);
    printf("0 ");
    n--;
    k--;
    if (n)
    {
        if (n > k)
        {
            for (int i = 0; i < n - k; i++)
            {
                printf("0 ");
            }
            n = k;
        }
        for (int i = 0; i < n; i++)
        {
            int now = i / 2 + 1;
            if (i & 1)
                now = -now;
            printf("%d ", now);
        }
        printf("\n");
    }
    return 0;
}