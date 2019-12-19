#include <iostream>

using namespace std;

long long Josephus(long long n, long long k, long long s = 1) // 人数 步长 起始位置
{
    if (k == 1)
        return ((n - 1) + s) % n;
    long long ans = 0;
    for (long long i = 2; i <= n;)
    {
        if (ans + k < i)
        {
            long long leap;
            if ((i - ans - 1) % (k - 1) == 0)
                leap = (i - ans - 1) / (k - 1) - 1;
            else
                leap = (i - ans - 1) / (k - 1);
            if (i + leap > n)
                return (ans + (n - (i - 1)) * k + s) % n;
            ans += leap * k;
            i += leap;
        }
        else
        {
            ans = (ans + k) % i;
            i++;
        }
    }
    return (ans + s) % n;
}

int main()
{
    long long n, k;
    while (cin >> n >> k)
    {
        long long ans = Josephus(n, k, 1);
        cout << (ans == 0 ? n : ans) << endl;
    }
    return 0;
}