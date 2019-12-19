#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, day[150], ans = 0;
        cin >> n >> m;
        day[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> day[i];
        }
        day[n + 1] = 101;
        if (n <= m)
        {
            ans = 100;
        }
        else
        {
            for (int i = 0; i < n - m + 1; i++)
            {
                ans = max(ans, day[m + 1 + i] - 1 - (day[i] + 1) + 1);
            }
        }
        cout << ans << endl;
    }
    return 0;
}
