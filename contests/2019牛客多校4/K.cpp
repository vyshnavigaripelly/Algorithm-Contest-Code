#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char s[100007];
int sufsum[100007];
int cnt[2], zero;

int main()
{
    scanf("%s", s + 1);
    int len = strlen(s + 1);
    for (int i = len; i > 0; i--)
    {
        sufsum[i] = s[i] - '0' + sufsum[i + 1];
        sufsum[i] %= 3;
        if (s[i] == '0')
            zero++;
    }
    long long ans = 0;
    for (int i = len; i > 0; i--)
    {
        if (s[i] == '0' && s[i + 1] == '0')
        {
            cnt[sufsum[i]]++;
        }
        ans += cnt[sufsum[i]];
    }
    ans += zero;
    printf("%lld\n", ans);
    return 0;
}