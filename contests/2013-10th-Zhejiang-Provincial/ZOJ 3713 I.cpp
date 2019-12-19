#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    getchar();
    while (t--)
    {
        string in;
        getline(cin, in);
        int n = in.length();
        if (n == 0)
        {
            printf("00");
        }
        else
        {
            while (n)
            {
                int tmp = n & ((1 << 7) - 1);
                if (n >> 7)
                {
                    tmp |= (1 << 7);
                }
                printf("%02X", tmp);
                n >>= 7;
            }
            for (int i = 0; i < in.length(); i++)
            {
                printf("%02X", in[i]);
            }
        }
        printf("\n");
    }
    return 0;
}
