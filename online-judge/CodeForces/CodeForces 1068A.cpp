#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, m, k, l;
    cin >> n >> m >> k >> l;
    long long ans = ((l + k) + m - 1) / m;
    if (l + k > n || ans * m > n)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << ans << endl;
    }
    return 0;
}