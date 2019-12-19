#include <iostream>
#include <cstdio>

using namespace std;

int ans[150007];

int main()
{
    int cnt = 0;
    for (int i = 1; i < 1044374; i++)
    {
        int tmp = i;
        while (true)
        {
            if (tmp < 10)
            {
                if (tmp == 0 || tmp == 1 || tmp == 7)
                {
                    ans[++cnt] = i;
                }
                break;
            }
            int sum = 0;
            while (tmp)
            {
                int k = tmp % 10;
                sum += k * k;
                tmp /= 10;
            }
            tmp = sum;
        }
    }
    int q;
    scanf("%d", &q);
    while (q--)
    {
        int k;
        scanf("%d", &k);
        printf("%d\n", ans[k]);
    }
    return 0;
}