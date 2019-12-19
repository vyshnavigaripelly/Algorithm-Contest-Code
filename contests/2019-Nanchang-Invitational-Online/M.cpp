#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

char a[100007], b[100007];
int len1;

int solve()
{
    int len2 = strlen(b), i = 0, j = 0;
    if (len2 > len1)
    {
        return 0;
    }
    while (j < len2 && i < len1)
    {
        if (a[i] == b[j])
        {
            i++, j++;
        }
        else
        {
            if (++i == len1)
            {
                return 0;
            }
        }
    }
    if (i >= len1 && j < len2)
    {
        return 0;
    }
    return 1;
}

int main()
{
    int t;
    scanf("%s %d", a, &t);
    len1 = strlen(a);
    while (t--)
    {
        scanf("%s", b);
        printf("%s\n", (solve() ? "YES" : "NO"));
    }
    return 0;
}
