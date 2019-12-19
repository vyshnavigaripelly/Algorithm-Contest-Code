#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        long long n, x, y, d;
        cin >> n >> x >> y >> d;
        long long ans = 0x3f3f3f3f3f3f;
        if (abs(y - x) % d == 0)
        {
            ans = abs(y - x) / d;
            cout << ans << endl;
        }
        else
        {
            long long sum1 = (x - 1) / d + (((x - 1) % d == 0) ? 0 : 1);
            long long sum2 = (n - x) / d + (((n - x) % d == 0) ? 0 : 1);
            if ((y - 1) % d == 0)
                ans = min(sum1 + (y - 1) / d, ans);
            if ((n - y) % d == 0)
                ans = min(sum2 + (n - y) / d, ans);
            if (ans != 0x3f3f3f3f3f3f)
                cout << ans << endl;
            else
                cout << -1 << endl;
        }
    }
    return 0;
}