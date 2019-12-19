#include <iostream>

using namespace std;

int arr[100007];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i += 2)
        {
            arr[i] = i / 2 + 1;
        }
        for (int i = 2; i <= n; i += 2)
        {
            arr[i] = i / 2 + (n + 1) / 2;
        }
        for (int i = 1; i <= n; i++)
            printf("%d ", arr[i]);
        puts("");
    }
    return 0;
}