#include <iostream>
using namespace std;

int ZellerFmla(int y, int m, int d)
{
    if (m == 1 || m == 2)
    {
        y--;
        m += 12;
    }
    int c = y / 100;
    y %= 100;
    int w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    if (w < 0)
    {
        w = (w % 7) + 7;
    }
    return w % 7;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int y, day;
        cin >> y;
        if (ZellerFmla(y, 5, 1) == 1)
        {
            day = 9;
        }
        else if (ZellerFmla(y, 5, 1) == 2 || ZellerFmla(y, 5, 1) == 0)
        {
            day = 6;
        }
        else
        {
            day = 5;
        }
        cout << day << endl;
    }
    return 0;
}
