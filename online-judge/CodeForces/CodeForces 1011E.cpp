#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, k, t, ans = 1;
    cin >> n >> k >> t;
    int gcd = __gcd(k, t);
    for (int i = 1; i < n; i++)
    {
        cin >> t;
        gcd = __gcd(gcd, t);
    }
    cout << k / gcd << endl;
    cout << 0;
    while (ans * gcd < k)
    {
        cout << " " << ans * gcd;
        ans++;
    }
    return 0;
}