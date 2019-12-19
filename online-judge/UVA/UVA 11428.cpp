#include <iostream>

using namespace std;

int n;

int solve(int y)
{
    int l = y + 1, r = y + 10000;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        long long ans = (mid - y) * (mid * mid + mid * y + y * y);
        if (ans == n)
        {
            return mid;
        }
        if (ans < n)
        {
            l = mid + 1;
        }
        if (ans > n)
        {
            r = mid - 1;
        }
    }
    return -1;
}

int main()
{
    while (cin >> n && n)
    {
        // x^3 - y^3 = (x - y)(x^2 + xy + y^2)
        // 0 < n < 10000, x > y > 0
        // x^3 - y^3 > (x - y)(3y^2)
        // 0 < y < 58
        int x = -1;
        for (int y = 0; y < 60; y++)
        {
            x = solve(y);
            if (x != -1)
            {
                cout << x << ' ' << y << endl;
                break;
            }
        }
        if (x == -1)
        {
            cout << "No solution" << endl;
        }
    }
    return 0;
}