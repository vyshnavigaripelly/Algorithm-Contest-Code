#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, m, a, b;
    cin >> n >> m >> a >> b;
    long long ans = min(((n / m + 1) * m - n) * a, (n - (n / m) * m) * b);
    cout << ans << endl;
    return 0;
}