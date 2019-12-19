#include <iostream>

using namespace std;

long long arr[50];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = n; i >= 0; i--)
        {
            scanf("%lld", &arr[i]);
        }
        if (n >= 3)
        {
            puts("No");
        }
        else if (n == 0 || n == 1)
        {
            puts("Yes");
        }
        else if (n == 2 && arr[1] * arr[1] - 4 * arr[2] * arr[0] >= 0)
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