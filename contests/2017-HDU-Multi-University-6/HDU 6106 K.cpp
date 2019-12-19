#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        while (n--)
        {
            int a, b, c, ab, bc, ac, abc;
            cin >> a >> b >> c >> ab >> bc >> ac >> abc;
            if (a >= ab && b >= ab && a >= ac && c >= ac && b >= bc && c >= bc && a >= abc && b >= abc && c >= abc && ab >= abc && ac >= abc && bc >= abc && ab + ac - abc <= a && ab + bc - abc <= b && ac + bc - abc <= c)
            {
                ans = max(ans, a + b + c - ab - ac - bc + abc);
            }
        }
        cout << ans << endl;
    }
    return 0;
}