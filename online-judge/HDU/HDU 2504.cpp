#include <iostream>
using namespace std;

int Gcd(int a, int b)
{
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        int c = 2 * b;
        while (Gcd(a, c) != b)
        {
            c += b;
        }
        cout << c << endl;
    }
    return 0;
}
