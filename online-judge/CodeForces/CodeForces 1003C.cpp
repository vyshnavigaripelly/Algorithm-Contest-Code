#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int arr[5123];

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 2; i <= n; i++)
    {
        arr[i] += arr[i - 1];
    }
    double ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i + k - 1; j <= n; j++)
        {
            ans = max(ans, (arr[j] - arr[i - 1]) * 1.0 / (j - i + 1));
        }
    }
    printf("%.8lf", ans);
    return 0;
}
