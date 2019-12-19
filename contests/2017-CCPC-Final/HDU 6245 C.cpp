#include <iostream>

using namespace std;

int x, y, k;

int check(int m)
{
    return m * y * 11 <= (k - m) * x * 11 + m * 9 * x;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        scanf("%d %d %d", &x, &y, &k);
        printf("Case #%d: ", cas);
        if (x > y)
        {
            printf("%d\n", k);
        }
        else
        {
            int ansl = 0, ansr = k, ans = -1;
            while (ansl <= ansr)
            {
                int ansm = (ansl + ansr) >> 1;
                if (check(ansm))
                {
                    ansl = ansm + 1;
                    ans = max(ans, ansm);
                }
                else
                {
                    ansr = ansm - 1;
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}