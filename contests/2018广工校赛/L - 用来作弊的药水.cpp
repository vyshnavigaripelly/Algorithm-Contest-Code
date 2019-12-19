#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        // lg(a^b) = b*lg(a)
        int x, a, y, b;
        cin >> x >> a >> y >> b;
        long long m = a * log10(x), n = b * log10(y);
        if (m == n)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
