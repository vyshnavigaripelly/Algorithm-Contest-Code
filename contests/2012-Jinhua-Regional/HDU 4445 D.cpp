#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

const double pi = acos(-1.0);
const double g = 9.8;

double v[100007];
double h, l1, r1, l2, r2, n;

int check(double ang)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        double t = (v[i] * sin(ang) + sqrt(v[i] * v[i] * sin(ang) * sin(ang) + 2 * g * h)) / g;
        double l = t * v[i] * cos(ang);
        if (l >= l2 && l <= r2)
        {
            return 0;
        }
        if (l >= l1 && l <= r1)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    while (cin >> n && n)
    {
        int ans = 0;
        cin >> h >> l1 >> r1 >> l2 >> r2;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        for (double ang = -pi / 2.0; ang <= pi / 2.0; ang += pi / 1000)
        {
            ans = max(ans, check(ang));
        }
        cout << ans << endl;
    }
    return 0;
}