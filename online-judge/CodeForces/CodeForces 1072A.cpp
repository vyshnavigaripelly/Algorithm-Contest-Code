#include <iostream>
using namespace std;

int main()
{
    int w, h, k;
    cin >> w >> h >> k;
    int ans = 0;
    while (k--)
    {
        ans += 2 * w + 2 * (h - 2);
        w -= 4;
        h -= 4;
    }
    cout << ans << endl;
    return 0;
}