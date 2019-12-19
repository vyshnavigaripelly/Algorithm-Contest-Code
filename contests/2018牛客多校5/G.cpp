#include <iostream>
#include <algorithm>

using namespace std;

int check(unsigned long long n)
{
    for (unsigned long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

unsigned long long arr[5];

int main()
{
    long long n, c;
    cin >> c >> n;
    if (c > n)
    {
        cout << -1 << endl;
        return 0;
    }
    n /= c;
    unsigned long long ans = 1;
    for (long long i = n; i >= max(0LL, n - 1000); i--)
    {
        for (long long j = n; j >= max(0LL, n - 1000); j--)
        {
            if (__gcd(i, j) == 1)
            {
                ans = max(ans, 1ULL * i * j);
            }
        }
    }
    ans *= c * c;
    cout << ans << endl;
    return 0;
}