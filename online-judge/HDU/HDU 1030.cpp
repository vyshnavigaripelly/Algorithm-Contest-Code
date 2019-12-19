#include <iostream>
#include <cmath>
using namespace std;

void find(int n, int &l, int &r, int &h)
{
    int colmax = 1;
    h = 1;
    while (n - colmax > 0)
    {
        n -= colmax;
        h++;
        colmax += 2;
    }
    l = (n + 1) / 2;
    r = (colmax - n) / 2 + 1;
}

int main()
{
    int m, n;
    while (cin >> m >> n)
    {
        int mL, mR, mH, nL, nR, nH, dL, dR, dH;
        find(m, mL, mR, mH);
        find(n, nL, nR, nH);
        dL = abs(mL - nL);
        dR = abs(mR - nR);
        dH = abs(mH - nH);
        cout << dL + dR + dH << endl;
    }
    return 0;
}
