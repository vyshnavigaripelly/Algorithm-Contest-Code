#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long L, v, l, r;
        cin >> L >> v >> l >> r;
        long long ans = L / v - (r / v - l / v) - (l % v == 0 ? 1 : 0);
        cout << ans << endl;
    }
    return 0;
}