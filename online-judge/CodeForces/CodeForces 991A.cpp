#include <iostream>
using namespace std;

int main()
{
    int a, b, c, n, ans;
    cin >> a >> b >> c >> n;
    ans = n - (a + b - c);
    if (a < c || b < c)
    {
        cout << -1;
    }
    else if (ans >= 1)
    {
        cout << ans;
    }
    else
    {
        cout << -1;
    }
    return 0;
}