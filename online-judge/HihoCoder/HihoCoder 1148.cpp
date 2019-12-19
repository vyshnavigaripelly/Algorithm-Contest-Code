#include <iostream>
#include <cstdio>
using namespace std;

string months[] = {"", "January", "February", "March", "April", "May", "June",
                   "July", "August", "September", "October", "November", "December"};

bool IsLeapYear(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
        return true;
    else
        return false;
}

int cal(int y)
{
    return y / 4 - y / 100 + y / 400;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        string sm, em;
        int sy, sd, ey, ed;
        cin >> sm;
        scanf("%d, %d", &sd, &sy);
        cin >> em;
        scanf("%d, %d", &ed, &ey);
        int smp, emp;
        for (int i = 1; i <= 12; i++)
        {
            if (sm == months[i])
            {
                smp = i;
            }
            if (em == months[i])
            {
                emp = i;
            }
        }
        int cnt = 0;
        if (sy + 1 < ey)
        {
            cnt = cal(ey - 1) - cal(sy);
        }
        if (IsLeapYear(sy) && smp <= 2)
        {
            cnt++;
        }
        if (IsLeapYear(ey) && (emp > 2 || (emp == 2 && ed == 29)))
        {
            cnt++;
        }
        if (IsLeapYear(sy) && sy == ey)
        {
            cnt--;
        }
        printf("Case #%d: %d\n", cas, cnt);
    }
    return 0;
}
