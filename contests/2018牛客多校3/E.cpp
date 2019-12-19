#include <iostream>
#include <cmath>
#include <map>
#include <unordered_map>
#include <vector>
#include <cstring>

using namespace std;

const int N = 1e6 + 7;
const int K = 131;

unsigned long long f[2 * N], p = 1;

unordered_map<unsigned long long, int> mp;
vector<int> ans[N];
char s[2 * N];

unsigned long long fpow(unsigned long long x, unsigned long long n)
{
    unsigned long long s = 1;
    while (n)
    {
        if (n & 1)
            s = s * x;
        x = x * x;
        n >>= 1;
    }
    return s;
}

int main()
{
    scanf("%s", s);
    int n = strlen(s);
    for (int i = 0; i < n; i++)
    {
        s[i + n] = s[i];
    }
    int len = n * 2;
    for (int i = 1; i <= len; i++)
    {
        f[i] = f[i - 1] * K + (s[i - 1] - 'a' + 1);
    }
    p = fpow(K, n + 1);
    int tot = 1;
    for (int i = 1; i <= n; i++)
    {
        unsigned long long hsh = f[i + n] - f[i - 1] * p;
        if (!mp.count(hsh))
        {
            mp[hsh] = tot;
            ans[tot].push_back(i - 1);
            tot++;
        }
        else
        {
            ans[mp[hsh]].push_back(i - 1);
        }
    }
    printf("%d\n", tot - 1);
    for (int i = 1; i < tot; i++)
    {
        printf("%d ", ans[i].size());
        for (auto j : ans[i])
        {
            printf("%d ", j);
        }
        puts("");
    }
    return 0;
}