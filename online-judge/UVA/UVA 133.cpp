#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int n, k, m, arr[30] = {0};
    while (~scanf("%d %d %d", &n, &k, &m))
    {
        if (n == 0 && k == 0 && m == 0)
        {
            break;
        }
        for (int i = 1; i <= n; i++)
        {
            arr[i] = i;
        }
        int left = n, pup = 1 - 1, pdown = n + 1;
        while (left > 0)
        {
            int dup = k, ddown = m;
            while (dup--)
            {
                do
                {
                    pup++;
                    if (pup > n)
                    {
                        pup -= n;
                    }
                } while (arr[pup] == 0);
            }
            while (ddown--)
            {
                do
                {
                    pdown--;
                    if (pdown < 1)
                    {
                        pdown += n;
                    }
                } while (arr[pdown] == 0);
            }
            if (pup != pdown)
            {
                printf("%3d%3d", pup, pdown);
                left -= 2;
            }
            else
            {
                printf("%3d", pup);
                left--;
            }
            arr[pup] = 0;
            arr[pdown] = 0;
            if (left > 0)
            {
                printf(",");
            }
        }
        printf("\n");
    }
    return 0;
}
