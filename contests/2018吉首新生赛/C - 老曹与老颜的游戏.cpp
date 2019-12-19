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
    int a, b, c;
    while (cin >> a >> b >> c)
    {
        int g = Gcd(a, b), flag = 0;
        if (c % g == 0)
        {
            for (int i = 0; i * a <= c; i++)
            {
                if ((c - a * i) % b == 0)
                {
                    flag = 1;
                }
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
