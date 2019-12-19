#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans1 = 0.5 * sqrt(8 * (n + k) + 9) - 1.5,
              ans2 = -0.5 * sqrt(8 * (n + k) + 9) - 1.5;
    cout << n - max(ans1, ans2) << endl;
    return 0;
}