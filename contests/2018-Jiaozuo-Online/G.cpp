#include <iostream>
#include <cstring>
using namespace std;

const int mod = 1e9 + 7;

char num[1000000];

long long FastPow(long long x, long long n, long long MOD)
{
    long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x % MOD;
        x = x * x % MOD;
        n >>= 1;
    }
    return s % MOD;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        cin >> num;
        long long ans = 0;
        for (int i = 0; i < strlen(num); i++)
        {
            long long tmp = ans;
            ans = ans * 10 + (num[i] - '0');
            ans %= (mod - 1);
        }
        if (ans == 0)
            ans = mod - 1;
        cout << FastPow(2, ans - 1, mod) << endl;
    }
    return 0;
}