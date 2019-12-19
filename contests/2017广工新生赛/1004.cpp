#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int a[10], cnt;

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        int count = 1;
        scanf("%d", &n);
        while (n != 0)
        {
            int temp = 1;
            int nn = n;
            while (nn != 0)
            {
                if (nn % 10)
                {
                    a[count] += temp;
                }
                nn /= 10;
                temp *= 10;
            }
            n -= a[count];
            count++;
        }
        sort(a + 1, a + count);
        printf("%d\n", count - 1);
        for (int i = 1; i < count; i++)
        {
            printf("%d ", a[i]);
        }
        printf("\n");
    }
    return 0;
}
