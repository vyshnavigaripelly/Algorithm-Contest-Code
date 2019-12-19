#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int main()
{
    int q, maxh = -1, maxw = -1;
    scanf("%d", &q);
    while (q--)
    {
        getchar();
        char c;
        int w, h;
        scanf("%c %d %d", &c, &w, &h);
        if (w > h)
        {
            swap(w, h);
        }
        if (c == '+')
        {
            maxh = max(maxh, h);
            maxw = max(maxw, w);
        }
        else
        {
            if (h >= maxh && w >= maxw)
            {
                puts("YES");
            }
            else
            {
                puts("NO");
            }
        }
    }
    return 0;
}
