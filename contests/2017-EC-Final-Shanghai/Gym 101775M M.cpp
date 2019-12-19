#include <iostream>

using namespace std;

int price[5];

int fun(int id)
{
    if (id <= 48)
        return 0;
    if (id <= 56)
        return 1;
    if (id <= 60)
        return 2;
    if (id <= 62)
        return 3;
    return 4;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int q, id, slary = 0;
        for (int i = 0; i < 5; i++)
        {
            scanf("%d", &price[i]);
        }
        scanf("%d", &q);
        while (q--)
        {
            scanf("%d", &id);
            slary += price[fun(id)];
        }
        printf("Case #%d: %d0000\n", cas, slary);
    }
    return 0;
}