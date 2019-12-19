#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

char m[5][5];

void ro(int x, int y, int n)
{
    while (n--)
    {
        swap(m[x + 1][y], m[x][y]);
        swap(m[x + 1][y + 1], m[x + 1][y]);
        swap(m[x][y + 1], m[x + 1][y + 1]);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        scanf("%s %s %s", m[0], m[1], m[2]);
        while (n--)
        {
            int a;
            char b;
            scanf("%d%c", &a, &b);
            int x = (((a - 1) & 2) > 0);
            int y = (((a - 1) & 1) > 0);
            if (b == 'C')
            {
                ro(x, y, 1);
            }
            else
            {
                ro(x, y, 3);
            }
        }
        printf("%s\n%s\n%s\n", m[0], m[1], m[2]);
    }
    return 0;
}