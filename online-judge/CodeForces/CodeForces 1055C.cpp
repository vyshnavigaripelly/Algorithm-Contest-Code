#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    long long la, ra, ta, lb, rb, tb;
    cin >> la >> ra >> ta >> lb >> rb >> tb;
    long long g = __gcd(ta, tb);
    long long d = la - lb;
    long long x = min(ra - la + 1, rb - lb + 1 - (d + abs(d) * g) % g);
    long long y = min(rb - lb + 1, ra - la + 1 - ((-d) + abs(d) * g) % g);
    // cout << x << ' ' << y << endl;
    cout << max(max(x, y), 0LL) << endl;
    return 0;
}