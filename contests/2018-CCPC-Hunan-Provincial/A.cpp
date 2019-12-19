#include <iostream>

using namespace std;

char str[10][20] = {"oooooooooooo", "..oo.o.o.o.o", "oooo.o.o.ooo", "o..o.o.o.o.o", "oooooooooooo"};

int main()
{
    int w;
    cin >> w;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                printf("%c", str[i][j * 3 + k]);
            }
            if (j != 3)
            {
                for (int k = 0; k < w; k++)
                {
                    printf(".");
                }
            }
        }
        puts("");
    }
    return 0;
}