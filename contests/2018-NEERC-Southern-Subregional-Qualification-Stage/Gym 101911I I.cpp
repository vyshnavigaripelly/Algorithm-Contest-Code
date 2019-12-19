#include <iostream>
#include <algorithm>

using namespace std;

int arr[1007];

int main()
{
    int n;
    scanf("%d", &n);
    int maxn = 0, minn = 2e9;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        maxn = max(maxn, arr[i]);
        minn = min(minn, arr[i]);
    }
    printf("%d\n", maxn - minn + 1 - n);
    return 0;
}