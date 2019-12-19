#include <iostream>
#include <set>
#include <cstring>

using namespace std;

const int N = 1E6 + 7;

set<int> pos[30];
char ans[N << 1], str[N];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(ans, 0, sizeof(ans));
        for (int i = 0; i < 26; i++)
        {
            pos[i].clear();
        }
        int n, len;
        cin >> n;
        scanf("%s", ans);
        len = strlen(ans);
        for (int i = 0; i < len; i++)
        {
            pos[ans[i] - 'a'].insert(i);
        }
        for (int i = 0; i < n - 1; i++)
        {
            int nowpos = -1;
            scanf("%s", str);
            int slen = strlen(str), cnt = 0;
            for (int j = 0; j < slen; j++)
            {
                auto pp = pos[str[j] - 'a'].lower_bound(nowpos);
                if (pp == pos[str[j] - 'a'].end())
                {
                    break;
                }
                if (*pp == nowpos)
                {
                    pp++;
                    if (pp == pos[str[j] - 'a'].end())
                    {
                        break;
                    }
                }
                cnt++;
                nowpos = *pp;
            }
            for (int j = cnt; j < slen; j++)
            {
                ans[len] = str[j];
                pos[str[j] - 'a'].insert(len);
                len++;
            }
        }
        printf("%s\n", ans);
    }
    return 0;
}