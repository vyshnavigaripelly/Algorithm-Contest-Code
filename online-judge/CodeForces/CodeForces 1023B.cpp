#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    long long n, k, l, r;
    cin >> n >> k;
    if (k % 2 == 0)
    {
        l = k / 2 - 1;
        r = k / 2 + 1;
    }
    else
    {
        l = k / 2;
        r = k / 2 + 1;
    }
    cout << max(min(l - 1 + 1, n - r + 1), 0LL) << endl;
    return 0;
}