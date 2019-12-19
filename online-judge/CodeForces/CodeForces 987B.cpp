#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x, y;
    cin >> x >> y;
    double ans1 = y * log(x);
    double ans2 = x * log(y);
    if (abs(ans1 - ans2) <= 1e-6)
    {
        cout << "=" << endl;
    }
    else if (ans1 < ans2)
    {
        cout << "<" << endl;
    }
    else
    {
        cout << ">" << endl;
    }
    return 0;
}
