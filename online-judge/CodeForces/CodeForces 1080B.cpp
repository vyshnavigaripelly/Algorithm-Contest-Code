#include <iostream>

using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        long long l, r, ans = 0, cnt, sgn = 1;
        cin >> l >> r;
        cnt = r - l + 1;
        if (r % 2 == 1)
        {
            sgn = -1;
        }
        ans = sgn * cnt / 2;
        if (cnt % 2 == 1)
        {
            ans += l * sgn;
        }
        cout << ans << endl;
    }
    return 0;
}