#include <iostream>
#include <cstring>

using namespace std;

char s[2007], t[30];
int cnt[26];

int main()
{
    int T;
    scanf("%d", &T);
    for (int cas = 1; cas <= T; cas++)
    {
        memset(cnt, 0, sizeof(cnt));
        scanf("%s %s", s, t);
        for (int i = 0; s[i]; i++)
        {
            cnt[s[i] - 'a']++;
        }
        int harm = 0, dry = 0, wet = 0, tot = 0;
        for (int i = 0; i < 26; i++)
        {
            if (t[i] == 'd')
            {
                dry += cnt[i];
            }
            else if (t[i] == 'w')
            {
                wet += cnt[i];
            }
            else
            {
                harm += cnt[i];
            }
            tot += cnt[i];
        }
        printf("Case #%d: ", cas);
        if (harm >= 0.25 * tot)
        {
            puts("Harmful");
        }
        else if (harm <= 0.1 * tot)
        {
            puts("Recyclable");
        }
        else if (dry >= 2 * wet)
        {
            puts("Dry");
        }
        else
        {
            puts("Wet");
        }
    }
    return 0;
}