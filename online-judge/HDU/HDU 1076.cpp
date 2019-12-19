#include <iostream>
using namespace std;

bool IsLeapYear(int year)
{
    if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int y, n, cnt = 0;
        cin >> y >> n;
        while (true)
        {
            if (IsLeapYear(y))
            {
                cnt++;
            }
            if (cnt == n)
            {
                break;
            }
            y++;
        }
        cout << y << endl;
    }
    return 0;
}
