#include <iostream>
using namespace std;

int arr[105];

int main()
{
    int n, k;
    cin >> n >> k;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > k)
        {
            ans += i;
            break;
        }
        if (i == n - 1)
        {
            ans = n;
        }
    }
    if (ans != n)
    {
        for (int i = n - 1; i >= 0; i--)
        {
            if (arr[i] > k)
            {
                ans += (n - 1 - i);
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}