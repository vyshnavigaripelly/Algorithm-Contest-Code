#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n, k, cnt1 = 0, cnt2 = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k == 1)
        {
            cnt1++;
        }
        else if (k == 2)
        {
            cnt2++;
        }
    }
    if (cnt2 > 0)
    {
        printf("2 ");
        cnt2--;
    }
    if (cnt1 > 0)
    {
        printf("1 ");
        cnt1--;
    }
    for (int i = 0; i < cnt2; i++)
    {
        printf("2 ");
    }
    for (int i = 0; i < cnt1; i++)
    {
        printf("1 ");
    }
    return 0;
}