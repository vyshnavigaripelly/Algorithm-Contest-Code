#include <iostream>
#include <cmath>

using namespace std;

int arr[16];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int x, y;
        for (int i = 0; i < 16; i++)
        {
            scanf("%d", &arr[i]);
            if (arr[i] == 0)
            {
                y = i / 4;
                x = i % 4;
            }
        }
        int cnt = 0;
        for (int i = 0; i < 16; i++)
        {
            if (arr[i] == 0)
            {
                continue;
            }
            for (int j = i + 1; j < 16; j++)
            {
                if (arr[j] == 0)
                {
                    continue;
                }
                if (arr[i] > arr[j])
                {
                    cnt++;
                }
            }
        }
        if ((cnt + abs(y - 3)) % 2 != 0)
        {
            puts("No");
        }
        else
        {
            puts("Yes");
        }
    }
    return 0;
}