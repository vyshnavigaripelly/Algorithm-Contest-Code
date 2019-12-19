#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, h, a, b, k;
    cin >> n >> h >> a >> b >> k;
    while (k--)
    {
        int ta, fa, tb, fb;
        cin >> ta >> fa >> tb >> fb;
        if (ta == tb)
        {
            cout << abs(fb - fa) << endl;
        }
        else if (fa > b && fb > b)
        {
            cout << fa - b + fb - b + abs(tb - ta) << endl;
        }
        else if (fa < a && fb < a)
        {
            cout << a - fa + a - fb + abs(tb - ta) << endl;
        }
        else
        {
            cout << abs(fb - fa) + abs(tb - ta) << endl;
        }
    }
    return 0;
}