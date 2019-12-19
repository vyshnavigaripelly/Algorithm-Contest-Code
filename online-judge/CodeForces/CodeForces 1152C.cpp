#include <iostream>
#include <algorithm>

using namespace std;

long long a, b, g, ans;

void solve(long long d)
{
    long long tmp = (d - a % d) % d;
    long long x = (a + tmp) * (b + tmp) / __gcd(a + tmp, b + tmp);
    if (x < g || (x == g && tmp < ans))
    {
        g = x;
        ans = tmp;
    }
}

int main()
{
    cin >> a >> b;
    g = a * b / __gcd(a, b);
    if (a < b)
    {
        swap(a, b);
    }
    long long tmp = a - b;
    for (long long d = 1; d * d <= tmp; d++)
    {
        if (tmp % d == 0)
        {
            solve(d);
            solve(tmp / d);
        }
    }
    cout << ans << endl;
    return 0;
}