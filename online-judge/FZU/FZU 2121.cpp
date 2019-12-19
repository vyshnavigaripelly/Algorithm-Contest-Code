#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        double s, h, vx, vy;
        cin >> s >> h >> vx >> vy;
        if (h > s * vy / vx - 5.0 / vx / vx * s * s)
        {
            cout << "poor Merida!" << endl;
        }
        else
        {
            cout << "good done!" << endl;
        }
    }
    return 0;
}
