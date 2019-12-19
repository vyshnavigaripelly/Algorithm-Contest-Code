#include <iostream>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        int ans = 0;
        while (n--)
        {
            int k;
            cin >> k;
            ans += k * k;
        }
        cout << ans << endl;
    }
    return 0;
}