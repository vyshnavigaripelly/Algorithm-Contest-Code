#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long i, t = 0;
    for (i = 0; t < m; i++)
    {
        t += i;
    }
    cout << max(0LL, n - 2 * m) << ' ' << n - i << endl;
    return 0;
}