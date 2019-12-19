#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, x, y;
    cin >> n;
    int ans = 0;
    string s = to_string(n);
    int len = s.length();
    x = (s[0] - '0') * (long long)(pow(10, len - 1) + 0.5) - 1;
    y = n - x;
    while (x != 0 || y != 0)
    {
        ans += x % 10 + y % 10;
        x /= 10;
        y /= 10;
    }
    cout << ans << endl;
    return 0;
}
