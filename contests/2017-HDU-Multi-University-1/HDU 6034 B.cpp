#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <algorithm>

using namespace std;

const int mod = 1e9 + 7,
          maxlen = 100000 + 7;

struct Node
{
    long long cnt[maxlen], zero;
};

char str[maxlen];
Node arr[26];
long long pow26[maxlen] = {1};

int main()
{
    for (int i = 1; i < maxlen; i++)
    {
        pow26[i] = pow26[i - 1] * 26 % mod;
    }
    long long n;
    for (int cas = 1; ~scanf("%lld", &n); cas++)
    {
        memset(arr, 0, sizeof(arr));
        for (int i = 0; i < 26; i++)
        {
            arr[i].zero = 1;
        }
        while (n--)
        {
            scanf("%s", str);
            int len = strlen(str);
            if (len > 1)
            {
                arr[str[0] - 'a'].zero = 0;
            }
            long long k = 1;
            int same = 1;
            for (int i = 0; i < len; i++)
            {
                int pos = len - i - 1;
                arr[str[pos] - 'a'].cnt[i]++;
                if (i >= 1 && str[i - 1] != str[i])
                {
                    same = 0;
                }
            }
            if (same)
            {
                arr[str[0] - 'a'].zero = 1;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < maxlen - 1; j++)
            {
                arr[i].cnt[j + 1] += arr[i].cnt[j] / 26;
                arr[i].cnt[j] %= 26;
            }
        }
        sort(arr, arr + 26, [](const Node &a, const Node &b) {
            for (int i = maxlen - 1; i >= 0; i--)
            {
                if (a.cnt[i] != b.cnt[i])
                {
                    return a.cnt[i] < b.cnt[i];
                }
            }
            return false;
        });
        int zeropos;
        for (int i = 0; i < 26; i++)
        {
            if (arr[i].zero == 1)
            {
                zeropos = i;
                break;
            }
        }
        long long ans = 0;
        int cur = 25;
        for (int i = 25; i >= 0; i--)
        {
            long long tmp = 0;
            if (i != zeropos)
            {
                for (int j = 0; j < maxlen; j++)
                {
                    tmp = tmp + pow26[j] * arr[i].cnt[j] % mod;
                    tmp %= mod;
                }
                ans += tmp * cur % mod;
                ans %= mod;
                cur--;
            }
        }
        printf("Case #%d: %lld\n", cas, ans % mod);
    }
    return 0;
}