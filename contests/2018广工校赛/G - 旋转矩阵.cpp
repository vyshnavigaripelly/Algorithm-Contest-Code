#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

char car[32][32];

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        memset(car, 0, sizeof(car));
        int r, c;
        cin >> r >> c;
        for (int i = 0; i < r; i++)
        {
            cin >> car[i];
        }
        string op;
        cin >> op;
        int L = 0, R = 0, oplen = op.length();
        for (int i = 0; i < oplen; i++)
        {
            if (op[i] == 'L')
            {
                L++;
            }
            else
            {
                R++;
            }
        }
        int d = (R - L) % 4;
        if (d < 0)
        {
            d += 4;
        }
        if (d % 2 != 0)
        {
            for (int i = 0; i < r; i++)
            {
                for (int j = 0; j < c; j++)
                {
                    if (car[i][j] == '-')
                    {
                        car[i][j] = '|';
                    }
                    else if (car[i][j] == '|')
                    {
                        car[i][j] = '-';
                    }
                }
            }
        }
        switch (d)
        {
            case 0:
            {
                cout << r << " " << c << endl;
                for (int i = 0; i < r; i++)
                {
                    for (int j = 0; j < c; j++)
                    {
                        cout << car[i][j];
                    }
                    cout << endl;
                }
                break;
            }
            case 1:
            {
                cout << c << " " << r << endl;
                for (int i = 0; i < c; i++)
                {
                    for (int j = r - 1; j >= 0; j--)
                    {
                        cout << car[j][i];
                    }
                    cout << endl;
                }
                break;
            }
            case 2:
            {
                cout << r << " " << c << endl;
                for (int i = r - 1; i >= 0; i--)
                {
                    for (int j = c - 1; j >= 0; j--)
                    {
                        cout << car[i][j];
                    }
                    cout << endl;
                }
                break;
            }
            case 3:
            {
                cout << c << " " << r << endl;
                for (int i = c - 1; i >= 0; i--)
                {
                    for (int j = 0; j < r; j++)
                    {
                        cout << car[j][i];
                    }
                    cout << endl;
                }
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
