#include <iostream>
#include <cstring>

using namespace std;

int cnts[30], cntt[30], cntp[30];

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        memset(cnts, 0, sizeof(cnts));
        memset(cntt, 0, sizeof(cntt));
        memset(cntp, 0, sizeof(cntp));
        string s, t, p;
        cin >> s >> t >> p;
        for (auto i : s)
        {
            cnts[i - 'a']++;
        }
        for (auto i : t)
        {
            cntt[i - 'a']++;
        }
        for (auto i : p)
        {
            cntp[i - 'a']++;
        }
        int flag = 1;
        for (int i = 0; i < 26; i++)
        {
            if (cnts[i] + cntp[i] < cntt[i])
            {
                flag = 0;
                break;
            }
        }
        if (!flag)
        {
            puts("NO");
        }
        else
        {
            int now = 0, flag2 = 0;
            for (int i = 0; i < t.size(); i++)
            {
                if (s[now] == t[i])
                {
                    now++;
                }
                if (now == s.size())
                {
                    flag2 = 1;
                    break;
                }
            }
            puts(flag2 ? "YES" : "NO");
        }
    }
    return 0;
}