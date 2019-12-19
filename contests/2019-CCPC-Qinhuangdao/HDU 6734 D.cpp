#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        if (n == 1)
        {
            puts("No");
        }
        else
        {
            while (n % 2 == 0 || n % 5 == 0)
            {
                if (n % 2 == 0)
                    n /= 2;
                if (n % 5 == 0)
                    n /= 5;
            }
            if (n == 1)
            {
                puts("No");
            }
            else
            {
                puts("Yes");
            }
        }
    }
    return 0;
}