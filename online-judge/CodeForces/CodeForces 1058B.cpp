#include <iostream>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;
    int m;
    cin >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        if (y >= -x + d && y <= -x + 2 * n - d && y <= x + d && y >= x - d)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}