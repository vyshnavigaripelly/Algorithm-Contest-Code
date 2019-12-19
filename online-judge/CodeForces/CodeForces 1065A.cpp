#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long s, a, b, c, ans = 0;
        cin >> s >> a >> b >> c;
        ans = s / c + s / c / a * b;
        cout << ans << endl;
    }
    return 0;
}