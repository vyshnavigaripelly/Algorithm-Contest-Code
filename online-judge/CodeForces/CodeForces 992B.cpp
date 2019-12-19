#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long l, r, x, y, ans = 0;
    cin >> l >> r >> x >> y;
    for (long long i = x; i * i <= x * y; i += x)
    {
        long long a = i, b = x * y / a;
        if (x * y % a == 0 && __gcd(a, b) == x)
        {
            if (a >= l && a <= r && b >= l && b <= r)
            {
                if (a != b)
                {
                    ans += 2;
                }
                else
                {
                    ans++;
                }
                // cout << a << ' ' << b << endl;
            }
        }
    }
    cout << ans << endl;
    return 0;
}