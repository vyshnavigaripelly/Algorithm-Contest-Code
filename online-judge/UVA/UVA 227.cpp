#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main()
{
    char map[7][7];
    for (int cas = 1;; cas++)
    {
        memset(map, ' ', sizeof(map));
        gets(map[0]);
        if (map[0][0] == 'Z')
        {
            break;
        }
        for (int i = 1; i < 5; i++)
        {
            gets(map[i]);
        }
        int sr = 0, sc = 0;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                if (map[i][j] == ' ')
                {
                    sr = i;
                    sc = j;
                }
            }
        }
        char op[2333] = {0};
        int opn = 0;
        while (scanf("%c", &op[opn]))
        {
            if (op[opn] == '0')
            {
                break;
            }
            else
            {
                opn++;
            }
        }
        getchar();
        int curr = sr, curc = sc, fail = 0;
        for (int i = 0; i < opn; i++)
        {
            switch (op[i])
            {
                case 'A':
                {
                    curr = sr - 1;
                    curc = sc;
                    break;
                }
                case 'B':
                {
                    curr = sr + 1;
                    curc = sc;
                    break;
                }
                case 'R':
                {
                    curr = sr;
                    curc = sc + 1;
                    break;
                }
                case 'L':
                {
                    curr = sr;
                    curc = sc - 1;
                    break;
                }
            }
            if (curr < 0 || curr > 4 || curc < 0 || curc > 4)
            {
                fail = 1;
            }
            else
            {
                map[sr][sc] = map[curr][curc];
                map[curr][curc] = ' ';
                sr = curr;
                sc = curc;
            }
        }
        if (cas != 1)
        {
            printf("\n");
        }
        printf("Puzzle #%d:\n", cas);
        if (fail)
        {
            printf("This puzzle has no final configuration.\n");
        }
        else
        {
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    printf("%c", map[i][j]);
                    if (j < 4)
                    {
                        printf(" ");
                    }
                }
                printf("\n");
            }
        }
    }
    return 0;
}
