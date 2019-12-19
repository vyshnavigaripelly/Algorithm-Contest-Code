#include <iostream>

using namespace std;

int main()
{
    int a, b, c;
    int n, m, q;
    cin >> a >> b >> c >> n >> m >> q;
    if (n >= a && n + m >= a + b && n + m + q >= a + b + c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}