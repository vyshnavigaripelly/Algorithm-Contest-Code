#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, m;
        int one = 0, two = 0, three = 0;
        scanf("%d %d", &n, &m);
        for (int i = 1; i <= n; i++)
        {
            int k;
            scanf("%d", &k);
            if (k == 1)
                one++;
            else if (k == 2)
                two++;
            else
                three++;
        }
        if (two + three >= 2)
        {
            puts("Yes");
        }
        else if (n == 1)
        {
            puts(m == 1 ? "Yes" : "No");
        }
        else if (two + three == 1)
        {
            if (one % 3 == 1)
                puts("Yes");
            else if (one % 3 == 2 || one % 3 == 0)
                puts(m == 1 ? "Yes" : "No");
        }
        else if (two + three == 0)
        {
            if (m == 1)
                puts(one % 3 != 0 ? "Yes" : "No");
            else
                puts(one % 3 == 1 ? "Yes" : "No");
        }
        else
        {
            puts("Yes");
        }
    }
    return 0;
}