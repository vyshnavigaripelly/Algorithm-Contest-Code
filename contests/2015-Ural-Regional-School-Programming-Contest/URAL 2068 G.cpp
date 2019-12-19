#include <iostream>

using namespace std;

int main()
{
    long long n, ans = 0;
    cin >> n;
    while (n--)
    {
        long long k;
        cin >> k;
        ans += k / 2;
    }
    cout << (ans % 2 == 1 ? "Daenerys" : "Stannis") << endl;
    return 0;
}