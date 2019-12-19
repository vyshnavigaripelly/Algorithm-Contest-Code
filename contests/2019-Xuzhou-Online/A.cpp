#include <bits/stdc++.h>

using namespace std;

unordered_set<long long> fib;

int n;
long long ai[101], bi[101];

__int128 mul(__int128 x, __int128 y, __int128 mod)
{
    __int128 ans = 0;
    while (y > 0)
    {
        if (y & 1)
            ans = (ans + x) % mod;
        x = (x + x) % mod;
        y >>= 1;
    }
    return ans;
}

__int128 exgcd(__int128 a, __int128 b, __int128 &x, __int128 &y)
{
    if (b == 0)
    {
        x = 1;
        y = 0;
        return a;
    }
    __int128 cnt = exgcd(b, a % b, x, y);
    __int128 idx = x;
    x = y;
    y = idx - a / b * y;
    return cnt;
}

__int128 excrt()
{
    __int128 x = 0, y = 0;
    __int128 M = bi[1], ans = ai[1];
    for (int i = 2; i <= n; i++)
    {
        __int128 a = M, b = bi[i], c = ((ai[i] - ans) % b + b) % b;
        __int128 gcd = exgcd(a, b, x, y), idx = b / gcd;
        if (c % gcd != 0)
            return -1;
        x = mul(x, c / gcd, idx);
        ans += x * M;
        M *= idx;
        ans = (ans % M + M) % M;
    }
    return (ans % M + M) % M;
}

int main()
{
    long long arr[100] = {1, 1};
    fib.insert(1);
    for (int i = 2;; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 2];
        fib.insert(arr[i]);
        if (arr[i] > (long long)1e16)
            break;
    }
    __int128 ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++) // ans % b[i] = a[i]
        cin >> bi[i] >> ai[i];
    ans = excrt();
    if (ans == -1)
    {
        puts("Tankernb!");
    }
    else if (fib.count((long long)ans))
    {
        puts("Lbnb!");
    }
    else
    {
        puts("Zgxnb!");
    }
    return 0;
}
