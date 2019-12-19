#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

char name[50], date[50];
int vis[20];

int main()
{
    puts("+------------------------------+--------+-------------+");
    puts("|Contest name                  |Date    |ABCDEFGHIJKLM|");
    puts("+------------------------------+--------+-------------+");
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        memset(vis, 0, sizeof(vis));
        gets(name);
        scanf("%s", date);
        int p, q;
        scanf("%d %d", &p, &q);
        getchar();
        while (q--)
        {
            char s[100];
            gets(s);
            if (s[2] == 'A')
            {
                vis[s[0] - 'A'] = 1;
            }
            else if (vis[s[0] - 'A'] != 1)
            {
                vis[s[0] - 'A'] = 2;
            }
        }
        printf("|%-30s|%8s|", name, date);
        for (int i = 0; i < 13; i++)
        {
            if (i < p)
            {
                if (vis[i] == 1)
                    printf("o");
                else if (vis[i] == 2)
                    printf("x");
                else if (vis[i] == 0)
                    printf(".");
            }
            else
                printf(" ");
        }
        printf("|\n");
        puts("+------------------------------+--------+-------------+");
    }
    return 0;
}