#include <iostream>

using namespace std;

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    int x1, y1, x2, y2;
    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
    int res = (m & 1) * (x1 - 1) + ((y1 - 1) & 1) * (x2 - x1 + 1) + ((m - y2) & 1) * (x2 - x1 + 1) + (m & 1) * (n - x2);
    cout << ((res + 1) >> 1) << endl;
    return 0;
}