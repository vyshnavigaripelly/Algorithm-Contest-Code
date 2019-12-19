#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

const double pi = acos(-1.0);

struct Point
{
    long long x, y;
    long long val;
    double ang;
} p[50007];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> p[i].x >> p[i].y >> p[i].val;
            if (p[i].x == 0)
            {
                p[i].ang = pi / 2;
            }
            p[i].ang = atan(1.0 * p[i].y / p[i].x);
        }
        sort(p, p + n, [](const Point &a, const Point &b) {
            return a.ang < b.ang;
        });
        long long suml = 0, sumr = 0;
        for (int i = 0; i < n; i++)
        {
            if (p[i].x >= 0)
            {
                suml += p[i].val;
            }
            else
            {
                sumr += p[i].val;
            }
        }
        long long ans = suml * sumr;
        for (int i = 0; i < n; i++)
        {
            if (p[i].x >= 0)
            {
                suml -= p[i].val;
                sumr += p[i].val;
            }
            else
            {
                suml += p[i].val;
                sumr -= p[i].val;
            }
            ans = max(ans, suml * sumr);
        }
        cout << ans << endl;
    }
    return 0;
}