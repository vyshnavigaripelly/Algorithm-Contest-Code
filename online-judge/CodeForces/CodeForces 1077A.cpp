#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long a, b, k;
        cin >> a >> b >> k;
        long long ans = (a - b) * (k / 2);
        if (k % 2 == 1)
        {
            ans += a;
        }
        cout << ans << endl;
    }
    return 0;
}