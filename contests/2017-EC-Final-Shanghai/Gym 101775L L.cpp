#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        printf("Case #%d: ", cas);
        if (n >= 16 && n % 2 == 0)
        {
            printf("Sheep\n");
        }
        else if (n >= 7 && n % 2 == 1)
        {
            printf("Panda\n");
        }
        else
        {
            printf("Draw\n");
        }
    }
    return 0;
}