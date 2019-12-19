#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int maxn = 100024;

int arr[maxn];
long long xxor[3][4][maxn];
int gui[3][4] = {1, 0, 0, 0,
                 1, 1, 0, 0,
                 0, 1, 0, 0};

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q;
        memset(xxor, 0, sizeof(xxor));
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 4; j++)
            {
                for (int k = 1; k + j <= n; k++)
                {
                    if (gui[i][(k - 1) % 4])
                    {
                        xxor[i][j][k + j] = xxor[i][j][k + j - 1] ^ arr[k + j];
                    }
                    else
                    {
                        xxor[i][j][k + j] = xxor[i][j][k + j - 1];
                    }
                }
            }
        }
        scanf("%d", &q);
        while (q--)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            if ((r - l + 1) % 4 == 0)
            {
                printf("0\n");
            }
            else
            {
                int num1 = ((r - l + 1) % 4) - 1;
                int num2 = (l - 1) % 4;
                long long aans = xxor[num1][num2][r] ^ xxor[num1][num2][l - 1];
                printf("%lld\n", aans);
            }
        }
    }
    return 0;
}
