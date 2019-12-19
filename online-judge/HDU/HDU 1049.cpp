#include <iostream>
using namespace std;

int main()
{
    int n, u, d;
    while (cin >> n >> u >> d && n != 0)
    {
        int t = 0, h = 0;
        while (h <= n)
        {
            h += u;
            t++;
            if (h >= n)
            {
                break;
            }
            h -= d;
            t++;
        }
        cout << t << endl;
    }
    return 0;
}
