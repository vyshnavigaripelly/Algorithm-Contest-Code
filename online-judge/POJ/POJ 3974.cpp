#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N = 1e6 + 7;
const int P = 13331;

unsigned long long p[N] = {1}, hsh[N], rhsh[N];
char s[N];

unsigned long long H(int l, int r)
{
    return hsh[r] - hsh[l - 1] * p[r - l + 1];
}

unsigned long long RH(int l, int r)
{
    return rhsh[l] - rhsh[r + 1] * p[r - l + 1];
}

int main()
{
    for (int i = 1; i < N; i++)
    {
        p[i] = p[i - 1] * P;
    }
    for (int cas = 1; scanf("%s", s + 1) && strcmp(s + 1, "END"); cas++)
    {
        memset(hsh, 0, sizeof(hsh));
        memset(rhsh, 0, sizeof(rhsh));
        int len = strlen(s + 1), ans = 0;
        for (int i = 1; i <= len; i++)
        {
            hsh[i] = hsh[i - 1] * P + s[i];
        }
        for (int i = len; i >= 1; i--)
        {
            rhsh[i] = rhsh[i + 1] * P + s[i];
        }
        for (int i = 1; i <= len; i++)
        {
            // odd length
            // 01[2345678]
            int l = 0, r = min(i - 1, len - i);
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (H(i - mid, i - 1) == RH(i + 1, i + mid))
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ans = max(ans, l * 2 + 1);
            // even length
            // 01[234567]8
            l = 0, r = min(i - 1, len - i + 1);
            while (l < r)
            {
                int mid = (l + r + 1) >> 1;
                if (H(i - mid, i - 1) == RH(i, i + mid - 1))
                {
                    l = mid;
                }
                else
                {
                    r = mid - 1;
                }
            }
            ans = max(ans, l * 2);
        }
        printf("Case %d: %d\n", cas, ans);
    }
    return 0;
}