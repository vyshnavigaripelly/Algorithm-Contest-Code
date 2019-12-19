#include <iostream>

using namespace std;

int arr[100007], brr[100007];

int main()
{
    int n, m, sum1 = 0, sum2 = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        if (arr[i] % 2 == 1)
        {
            sum1++;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> brr[i];
        if (brr[i] % 2 == 1)
        {
            sum2++;
        }
    }
    cout << min(sum1, m - sum2) + min(n - sum1, sum2) << endl;
    return 0;
}