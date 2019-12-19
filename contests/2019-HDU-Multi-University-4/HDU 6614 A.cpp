#include <iostream>
#include <cmath>

using namespace std;

const int N = 2e5 + 7;

int n, ans[N];

int mypow(int x)
{
    int ret = 1;
    for (int i = 1; i <= x; i++)
    {
        ret *= 2;
    }
    return ret;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int sum = 0;
        scanf("%d", &n);
        for (int i = 2; i <= n; i++)
        {
            int tmp = i, cnt = 0;
            while (tmp)
            {
                if ((tmp & 1) == 0)
                {
                    ans[i] = mypow(cnt);
                    break;
                }
                tmp >>= 1;
                cnt++;
            }
            if (!tmp)
            {
                if (i != n)
                    ans[i] = i + 1;
                else
                {
                    sum++;
                    ans[i] = 1;
                }
            }
        }
        printf("%d\n", sum);
        for (int i = 2; i <= n; i++)
        {
            printf("%d", ans[i]);
            if (i != n)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}