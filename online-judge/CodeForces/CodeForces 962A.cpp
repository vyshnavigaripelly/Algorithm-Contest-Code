#include <iostream>
#include <cstdio>
using namespace std;

int arr[200007];

int main()
{
    int n;
    double sum = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }
    int s = 0;
    for (int i = 0; i < n; i++)
    {
        s += arr[i];
        if (s >= sum / 2)
        {
            printf("%d\n", i + 1);
            break;
        }
    }
    return 0;
}
