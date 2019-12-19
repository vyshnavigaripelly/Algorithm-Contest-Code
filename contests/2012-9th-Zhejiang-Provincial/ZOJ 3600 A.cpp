#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int cas;
    cin >> cas;
    while (cas--)
    {
        int d, t;
        cin >> d >> t;
        double ans1 = 11, ans2 = 11;
        if (d > 3 && d <= 10)
        {
            ans1 += (d - 3) * 2;
            ans2 += (d - 3) * 2.5;
        }
        else if (d > 10)
        {
            ans1 += 7 * 2 + (d - 10) * 3;
            ans2 += 7 * 2.5 + (d - 10) * 3.75;
        }
        ans1 += 2.0 * t / 5;
        ans2 += 2.5 * t / 4.0;
        ans1 = round(ans1);
        ans2 = round(ans2);
        cout << abs(ans1 - ans2) << endl;
    }
    return 0;
}