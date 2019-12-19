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
        int n;
        cin >> n;
        arr[0] = -2;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i];
        }
        arr[n + 1] = -2;
        int cnt = 1, ans = 1;
        for (int i = 1; i <= n + 1; i++)
        {
            if (arr[i] == arr[i - 1] + 1)
            {
                cnt++;
            }
            else
            {
                ans = max(ans, cnt);
                cnt = 1;
            }
        }
        cout << ans << endl;
    }
    return 0;
}