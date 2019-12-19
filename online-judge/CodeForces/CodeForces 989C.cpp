#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    char map[55][55] = {0};
    memset(map, 'C', 25 * 55);
    memset(map + 25, 'B', 25 * 55);
    int rr = 0, cc = 0;
    c--;
    b--;
    int isA = 1, isC = 1;
    while (a > 0 && b > 0)
    {
        if (isA)
        {
            map[rr][cc] = 'A';
            a--;
        }
        else
        {
            map[rr][cc] = 'B';
            b--;
        }
        isA = !isA;
        cc++;
        if (cc == 49)
        {
            cc = 0;
            rr++;
        }
    }
    rr += 2;
    cc = 0;
    while (a--)
    {
        map[rr][cc] = 'A';
        cc += 2;
        if (cc == 50)
        {
            cc = 0;
            rr += 2;
        }
    }
    while (b--)
    {
        map[rr][cc] = 'B';
        cc += 2;
        if (cc == 50)
        {
            cc = 0;
            rr += 2;
        }
    }
    rr = 49;
    cc = 0;
    while (c > 0 && d > 0)
    {
        if (isC)
        {
            map[rr][cc] = 'C';
            c--;
        }
        else
        {
            map[rr][cc] = 'D';
            d--;
        }
        isC = !isC;
        cc++;
        if (cc == 49)
        {
            cc = 0;
            rr--;
        }
    }
    rr -= 2;
    cc = 0;
    while (c--)
    {
        map[rr][cc] = 'C';
        cc += 2;
        if (cc == 50)
        {
            cc = 0;
            rr -= 2;
        }
    }
    while (d--)
    {
        map[rr][cc] = 'D';
        cc += 2;
        if (cc == 50)
        {
            cc = 0;
            rr -= 2;
        }
    }
    cout << "50 50" << endl;
    for (int i = 0; i < 50; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            cout << map[i][j];
        }
        cout << endl;
    }
    return 0;
}