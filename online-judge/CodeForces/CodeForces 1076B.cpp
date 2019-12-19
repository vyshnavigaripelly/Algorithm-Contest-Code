#include <iostream>
using namespace std;

int IsPrimeNum(long long n)
{
    if (n == 1)
        return 0;
    for (long long i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }
    return 1;
}

long long solve(long long n)
{
    for (long long i = 2; i * i <= n; i++)
    {
        if (IsPrimeNum(i) && n % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    long long n;
    cin >> n;
    if (IsPrimeNum(n))
    {
        cout << 1 << endl;
    }
    else
    {
        cout << (n - solve(n)) / 2 + 1 << endl;
    }
    return 0;
}