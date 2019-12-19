#include <iostream>
using namespace std;

long long Gcd(long long a, long long b)
{
    long long c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

long long Lcm(long long a, long long b)
{
    return a * b / Gcd(a, b);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        long long a[50];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        long long s = a[0];
        for (int i = 0; i < n; i++)
        {
            s = Lcm(s, a[i]);
        }
        cout << s << endl;
    }
    return 0;
}
