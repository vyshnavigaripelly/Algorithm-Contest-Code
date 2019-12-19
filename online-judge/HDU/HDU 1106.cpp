#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[1007][1007];
int arr[1007];

int main()
{
    char c;
    int cnt = 0, n = 0;
    while (~scanf("%[^5\n]", s[cnt]))
    {
        c = getchar();
        if (s[cnt][0])
        {
            sscanf(s[cnt], "%d", &arr[n++]);
        }
        cnt++;
        if (c == '\n')
        {
            sort(arr, arr + n);
            for (int i = 0; i < n; i++)
            {
                printf("%d", arr[i]);
                if (i != n - 1)
                {
                    printf(" ");
                }
            }
            puts("");
            n = 0;
            cnt = 0;
            memset(s, 0, sizeof(s));
        }
    }
    return 0;
}