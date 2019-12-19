#include <iostream>
#include <cmath>

using namespace std;

const double g = 9.8;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double a, b, x, y;
        cin >> a >> b >> x >> y;
        double ang = atan(b / a);
        double Px = x, Py = -b / a * x; // first collision position
        double h = y - Py; // first collision distance
        // W = mgh = 1/2 * m * v0^2
        double V0 = sqrt(2 * g * h); // velocity after collision
        double V0x = V0 * sin(ang), V0y = V0 * cos(ang);
        double Gx = g * sin(ang), Gy = g * cos(ang);
        double T = 2 * V0y / Gy;
        // P->O
        double sPO = -x / cos(ang);
        // m * Gx * sPO = 1/2 * m * Vx^2 - 1/2 * m * V0x^2
        double Vx = sqrt(2 * Gx * sPO + V0x * V0x); // end velocity
        double t = (Vx - V0x) / Gx;

        double ans = (int)(t / T) + 1;

        cout << ans << endl;
    }
    return 0;
}