#include <iostream>
#include <cmath>
#include <cstring>

const int N = 1e5 + 7;

char arr[N], brr[N];

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m, tmp;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &tmp);
            arr[i] = tmp + '0';
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d", &tmp);
            brr[i] = tmp + '0';
        }
        arr[n] = brr[m] = '\0';
        int posa = 0, posb = 0;
        printf("Case %d: ", cas);
        while (posa < n && posb < m)
        {
            if (arr[posa] < brr[posb])
            {
                printf("%c", brr[posb++]);
            }
            else if (arr[posa] > brr[posb])
            {
                printf("%c", arr[posa++]);
            }
            else
            {
                int flag = strcmp(arr + posa, brr + posb);
                if (flag < 0)
                {
                    while (arr[posa] == brr[posb])
                    {
                        if (posb >= m)
                            break;
                        printf("%c", brr[posb++]);
                    }
                }
                else
                {
                    while (arr[posa] == brr[posb])
                    {
                        if (posa >= n)
                            break;
                        printf("%c", arr[posa++]);
                    }
                }
            }
        }
        while (posa < n)
            printf("%c", arr[posa++]);
        while (posb < m)
            printf("%c", brr[posb++]);
        puts("");
    }
    return 0;
}