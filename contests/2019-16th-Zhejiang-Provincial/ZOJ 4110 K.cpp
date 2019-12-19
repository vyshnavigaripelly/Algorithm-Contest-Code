#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 7;
long long cnt = 0;
char ma[N * 2], a[N], b[N];
int mp[N * 2];

void manacher(char s[], int len)
{
    int l = 0;
    ma[l++] = '$';
    ma[l++] = '#';
    for (int i = 0; i < len; i++)
    {
        ma[l++] = s[i];
        ma[l++] = '#';
    }
    ma[l] = 0;
    int mx = 0, id = 0;
    for (int i = 0; i < l; i++)
    {
        mp[i] = mx > i ? min(mp[2 * id - i], mx - i) : 1;
        while (ma[i + mp[i]] == ma[i - mp[i]])
            mp[i]++;
        if (i + mp[i] > mx)
        {
            mx = i + mp[i];
            id = i;
        }
        cnt += 1LL * mp[i] / 2;
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s %s", a, b);
        int len = strlen(a);
        if (strcmp(a, b) == 0)
        {
            cnt = 0;
            manacher(a, len);
            printf("%lld\n", cnt);
        }
        else
        {
            long long ans = 1;
            int l = 0, r = len - 1;
            for (int i = 0; i < len; i++)
            {
                if (a[i] != b[i])
                {
                    l = i;
                    break;
                }
            }
            for (int i = len - 1; i >= 0; i--)
            {
                if (a[i] != b[i])
                {
                    r = i;
                    break;
                }
            }
            for (int i = l, j = 0; i <= (l + r) / 2; i++, j++)
            {
                swap(a[i], a[r - j]);
            }
            if (strcmp(a, b) == 0)
            {
                l--, r++;
                while (a[l] == b[l] && a[l] == a[r] && a[r] == b[r] && l >= 0 && r <= len - 1)
                {
                    ans++;
                    l--, r++;
                }
            }
            else
            {
                ans = 0;
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}