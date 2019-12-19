#include <iostream>
using namespace std;

int main()
{
    int n, ans = 0;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        while (k != 0)
        {
            if (k % 256 == 97)
            {
                ans++;
            }
            k /= 256;
        }
    }
    cout << ans << endl;
    return 0;
}