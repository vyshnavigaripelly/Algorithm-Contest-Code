#include <iostream>
#include <cmath>

using namespace std;

long long x[200007], y[200007];

int main()
{
    long long x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.length(); i++)
    {
        x[i + 1] = x[i] + (s[i] == 'L' ? -1 : (s[i] == 'R' ? 1 : 0));
        y[i + 1] = y[i] + (s[i] == 'D' ? -1 : (s[i] == 'U' ? 1 : 0));
    }
    long long l = 1, r = 2e14, ans = -1;
    while (l <= r)
    {
        long long mid = (l + r) / 2;
        if (abs(x1 + x[n] * (mid / n) + x[mid % n] - x2) + abs(y1 + y[n] * (mid / n) + y[mid % n] - y2) <= mid)
        {
            r = mid - 1;
            ans = mid;
        }
        else
        {
            l = mid + 1;
        }
    }
    cout << ans << endl;
    return 0;
}