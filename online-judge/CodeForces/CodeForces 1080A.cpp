#include <iostream>

using namespace std;

int main()
{
    long long n, k;
    cin >> n >> k;
    long long ans = n * 2 / k + (n * 2 % k != 0) + n * 5 / k + (n * 5 % k != 0) + n * 8 / k + (n * 8 % k != 0);
    cout << ans << endl;
    return 0;
}