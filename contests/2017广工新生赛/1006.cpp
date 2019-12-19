#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n, sum, n5, n7, n35, s5, s7, s35;
        cin >> n;
        n5 = n / 5;
        n7 = n / 7;
        n35 = n / 35;
        s5 = 5 * n5 * (n5 + 1) / 2;
        s7 = 7 * n7 * (n7 + 1) / 2;
        s35 = 35 * n35 * (n35 + 1) / 2;
        sum = s5 + s7 - s35;
        cout << sum << endl;
    }
    return 0;
}
