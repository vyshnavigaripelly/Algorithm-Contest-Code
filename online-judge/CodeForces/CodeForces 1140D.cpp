#include <iostream>

using namespace std;

int main()
{
    long long n;
    cin >> n;
    long long ans = 0;
    for (int i = 2; i <= n - 1; ++i)
    {
        ans += 1LL * i * i + i;
    }
    cout << ans << endl;
    return 0;
}