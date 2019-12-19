#include <iostream>
using namespace std;

long long Fact(int n) // 0 <= n <= 20
{
    long long s = 1;
    for (int i = 1; i <= n; i++)
        s *= i;
    return s;
}

long long nCr(int n, int r) // 0 <= r <= n <= 20
{
    return Fact(n) / Fact(r) / Fact(n - r);
}

long long StagFmla(int n)
{
    // Staggered Formula
    // D(0) = 0, D(1) = 0, D(2) = 1
    // D(n) = (n-1) * (D(n-1) + D(n-2))
    long long s = 1, sp1 = 0, sp2 = 0;
    if (n == 0 || n == 1)
        return 0;
    else if (n == 2)
        return 1;
    else
    {
        for (int i = 3; i <= n; i++)
        {
            sp2 = sp1;
            sp1 = s;
            s = (i - 1) * (sp1 + sp2);
        }
        return s;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        cout << StagFmla(n) << endl;
    }
    return 0;
}
