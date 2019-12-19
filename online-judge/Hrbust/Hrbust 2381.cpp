#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long ans = x / 4.0 - y / 4.0 * 3;
        cout << ans << endl;
    }
    return 0;
}