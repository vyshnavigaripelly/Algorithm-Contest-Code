#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int num;
        scanf("%d", &num);
        if (num == 1)
            printf("5\n");
        else
            printf("%d\n", num + 5);
    }
    return 0;
}