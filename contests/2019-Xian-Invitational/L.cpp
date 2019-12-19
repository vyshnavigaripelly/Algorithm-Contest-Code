#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    if (n >= 1 && n <= 3)
    {
        int arr[] = {0, 1, 2, 6};
        printf("%d\n", arr[n]);
    }
    else
    {
        int ans;
        int t = n % 4;
        if (t == 1)
        {
            ans = n / 4;
            ans = 10 + (ans - 1) * 8;
        }
        else if (t == 2)
        {
            ans = n / 4;
            ans = 6 + (ans - 1) * 4;
        }
        else if (t == 3)
        {
            ans = 12;
        }
        else if (t == 0)
        {
            ans = 4;
        }
        printf("%d\n", ans);
    }
    return 0;
}