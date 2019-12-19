#include <iostream>
#include <algorithm>
using namespace std;

int arr[100007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        sort(arr, arr + n);
        long long sum = 0;
        for (int i = 0; i < m; i++)
        {
            sum += arr[i] * arr[2 * m - i - 1];
        }
        cout << sum << endl;
    }
    return 0;
}