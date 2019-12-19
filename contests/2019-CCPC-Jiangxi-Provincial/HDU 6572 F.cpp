#include <iostream>
#include <algorithm>

using namespace std;

long long cnt[30];

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < n; i++)
    {
        cnt[s[i] - 'a']++;
    }
    long long p = cnt['a' - 'a'] * cnt['v' - 'a'] * cnt['i' - 'a'] * cnt['n' - 'a'];
    long long q = n * n * n * n;
    long long g = __gcd(p, q);
    printf("%lld/%lld\n", p / g, q / g);
    return 0;
}