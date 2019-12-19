#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

pair<long long, long long> calwb(long long x0, long long y0, long long x1, long long y1)
{
    long long w = x1 - x0 + 1, h = y1 - y0 + 1;
    if (h % 2 == 0 || w % 2 == 0)
    {
        return make_pair(w * h / 2, w * h / 2);
    }
    if ((x0 + y0) % 2 == 0) // white
    {
        return make_pair(w * h / 2 + 1, w * h / 2);
    }
    else
    {
        return make_pair(w * h / 2, w * h / 2 + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, m;
        cin >> n >> m;
        long long fx0, fy0, fx1, fy1;
        cin >> fx0 >> fy0 >> fx1 >> fy1;
        long long sx0, sy0, sx1, sy1;
        cin >> sx0 >> sy0 >> sx1 >> sy1;
        long long cx0, cy0, cx1, cy1;
        cx0 = max(fx0, sx0);
        cy0 = max(fy0, sy0);
        cx1 = min(fx1, sx1);
        cy1 = min(fy1, sy1);

        pair<long long, long long> total = calwb(1, 1, m, n), fi = calwb(fx0, fy0, fx1, fy1), se = calwb(sx0, sy0, sx1, sy1), c = calwb(cx0, cy0, cx1, cy1);

        long long tw = total.first, tb = total.second;
        long long fw = fi.first, fb = fi.second;
        long long sw = se.first, sb = se.second;
        long long cw = c.first, cb = c.second;

        if (cx0 > cx1 || cy0 > cy1)
        {
            cw = cb = 0;
        }

        long long ansb, answ;
        answ = tw + fb - sw - cb;
        ansb = tb - fb + sw + cb;
        cout << answ << ' ' << ansb << endl;
    }
    return 0;
}