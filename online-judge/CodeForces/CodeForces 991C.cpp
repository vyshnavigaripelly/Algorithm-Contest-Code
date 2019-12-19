#include <iostream>
#include <algorithm>
using namespace std;

long long n;

int check(long long k)
{
    long long sum = n, eat = 0;
    while (sum > 0)
    {
        eat += min(sum, k);
        sum -= min(sum, k);
        sum -= sum / 10;
    }
    if (eat * 2 >= n)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    cin >> n;
    long long l = 0, m, r = n;
    while (l + 1 < r)
    {
        m = (l + r) / 2;
        if (check(m))
        {
            r = m;
        }
        else
        {
            l = m;
        }
    }
    cout << r << endl;
    return 0;
}