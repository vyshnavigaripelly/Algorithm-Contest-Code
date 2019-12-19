#include <iostream>

using namespace std;

int main()
{
    long long n, m;
    cin >> n >> m;
    long long ans = m / n;
    if (m % n)
    {
        ans++;
    }
    cout << ans << endl;
    return 0;
}