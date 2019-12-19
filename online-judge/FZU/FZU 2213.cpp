#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double x1, y1, r1, x2, y2, r2;
        cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
        double dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
        if (x1 == x2 && r1 == r2 && y1 == y2)
        {
            cout << -1 << endl;
        }
        else if (dist < fabs(r1 - r2))
        {
            cout << 0 << endl;
        }
        else if (dist == fabs(r1 - r2))
        {
            cout << 1 << endl;
        }
        else if (dist > fabs(r1 - r2) && r1 + r2 > dist)
        {
            cout << 2 << endl;
        }
        else if (dist == r1 + r2)
        {
            cout << 3 << endl;
        }
        else if (dist > r1 + r2)
        {
            cout << 4 << endl;
        }
    }
    return 0;
}