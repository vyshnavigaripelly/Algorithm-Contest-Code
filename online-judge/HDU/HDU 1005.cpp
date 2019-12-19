#include <iostream>
using namespace std;

int main()
{
    int a, b, n;
    while (cin >> a >> b >> n && (a || b || n))
    {
        int cycle, fib[100] = {1, 1};
        for (int i = 2; i < 100; i++)
        {
            fib[i] = (a * fib[i - 1] + b * fib[i - 2]) % 7;
            if (fib[i] == 1 && fib[i - 1] == 1)
            {
                cycle = i - 1;
                break;
            }
        }
        cout << fib[(n - 1) % cycle] << endl;
    }
    return 0;
}
