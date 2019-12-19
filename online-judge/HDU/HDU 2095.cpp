#include <cstdio>

int main()
{
    for (int n; scanf("%d", &n) && n;)
        for (int q, t = 0; n-- || !printf("%d\n", t); scanf("%d", &q), t ^= q)
            ;
    return 0;
}