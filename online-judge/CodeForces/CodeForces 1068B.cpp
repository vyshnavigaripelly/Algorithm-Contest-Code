#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n;
    long long ans = 0;
    cin >> n;
    for (long long i = 1; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            if (n / i == i)
            {
                ans++;
            }
            else
            {
                ans += 2;
            }
        }
    }
    cout << ans << endl;
    return 0;
}