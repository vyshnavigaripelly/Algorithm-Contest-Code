#include <iostream>
#include <algorithm>

using namespace std;

string str[100007];
int a[10];
int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int leap(int y)
{
    return y % 400 == 0 || (y % 4 == 0 && y % 100 != 0);
}

int zeller(int y, int m, int d)
{
    if (m == 1 || m == 2)
    {
        y--;
        m += 12;
    }
    int c = y / 100;
    y %= 100;
    int w = y + y / 4 + c / 4 - 2 * c + 26 * (m + 1) / 10 + d - 1;
    return (w % 7 + 7) % 7;
}

int check(int y, int m, int d)
{
    return !(y < 1600 || y > 9999 || m < 1 || m > 12 ||
             d < 1 || d > days[m] + (leap(y) && m == 2) ||
             zeller(y, m, d) != 5);
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            cin >> str[i];
        }
        sort(str, str + n);
        int tot = unique(str, str + n) - str;
        for (int i = 0; i < 10; i++)
        {
            a[i] = i;
        }
        int flag = 0;
        do
        {
            flag = 1;
            for (int i = 0; i < tot; i++)
            {
                int y = a[str[i][0] - 'A'] * 1000 + a[str[i][1] - 'A'] * 100 + a[str[i][2] - 'A'] * 10 + a[str[i][3] - 'A'];
                int m = a[str[i][5] - 'A'] * 10 + a[str[i][6] - 'A'];
                int d = a[str[i][8] - 'A'] * 10 + a[str[i][9] - 'A'];
                if (!check(y, m, d))
                {
                    flag = 0;
                    break;
                }
            }
            if (flag)
            {
                break;
            }
        } while (next_permutation(a, a + 10));
        printf("Case #%d: ", cas);
        if (flag)
        {
            for (int i = 0; i < 10; i++)
            {
                printf("%d", a[i]);
            }
            puts("");
        }
        else
        {
            puts("Impossible");
        }
    }
    return 0;
}