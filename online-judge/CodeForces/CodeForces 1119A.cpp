#include <iostream>

using namespace std;

int arr[300007];

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    int ans = 1;
    for (int i = 1; i < n; i++)
    {
        if (arr[i] != arr[n])
        {
            ans = max(ans, n - i);
            break;
        }
    }
    for (int i = n; i > 1; i--)
    {
        if (arr[i] != arr[1])
        {
            ans = max(ans, i - 1);
            break;
        }
    }
    cout << ans << endl;
    return 0;
}