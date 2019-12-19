#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int t = ceil(sqrt(n));
    if (n > (t - 1) * t)
    {
        cout << 2 * 2 * t << endl;
    }
    else
    {
        cout << 2 * (t + t - 1) << endl;
    }
    return 0;
}
