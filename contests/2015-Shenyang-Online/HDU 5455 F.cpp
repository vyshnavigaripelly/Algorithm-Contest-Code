#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        string s;
        cin >> s;
        int ok = 1, f = 1;
        int ans = 0, flag = 1, len = s.length();
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != 'f')
            {
                f = 0;
            }
            if (s[i] != 'c' && s[i] != 'f')
            {
                ok = 0;
            }
        }
        if (!ok)
        {
            printf("Case #%d: %d\n", cas, -1);
            continue;
        }
        if (f)
        {
            printf("Case #%d: %d\n", cas, (len + 1) / 2);
            continue;
        }
        s += s;
        int pos = 0;
        while (s[pos] == 'f')
            pos++;
        int cnt = 0;
        for (int i = pos + 1; i < pos + len; i++)
        {
            if (s[i] == 'c')
            {
                if (cnt >= 2)
                {
                    ans++;
                }
                else
                {
                    flag = 0;
                }
                cnt = 0;
            }
            else if (s[i] == 'f')
            {
                cnt++;
            }
        }
        if (cnt >= 2)
        {
            ans++;
        }
        else
        {
            flag = 0;
        }
        if (flag == 0)
            ans = -1;
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}