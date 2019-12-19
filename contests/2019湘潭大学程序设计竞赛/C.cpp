#include <iostream>

using namespace std;

long long l, r;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long ans = 1;
        long long ll, rr;
        cin >> l >> r;
        if (r < 193)
        {
            if (l == 1)
                ans = 1;
            else
                ans = 0;
        }
        else
        {
            long long posr = 1LL * (r - 193) / 192 + 1;
            long long posl = 1LL * (l - 193) / 192 + 1;
            if (posl == 0)
                posl++;
            long long n = posr - posl + 1;
            long long a1 = 193 + (posl - 1) * 192;
            if (a1 < l)
            {
                a1 += 192;
                n--;
            }
            long long s = 1LL * n * a1 + n * (n - 1) / 2 * 192;
            if (l == 1)
                s++;
            cout << s << endl;
            continue;
        }
        cout << ans << endl;
    }
    return 0;
}