#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int pos[207] = {1}, cnt[207];

long long check(string s)
{
    int len = s.length();
    if (isalpha(s[0]) || isalpha(s[len - 1]))
    {
        return -1;
    }
    else if (s[0] == '0' && len != 1)
    {
        return -1;
    }
    long long ans = 0;
    for (int i = 0; i < len; i++)
    {
        if (isdigit(s[i]))
        {
            ans = ans * 10 + (s[i] - '0');
        }
    }
    return ans;
}

int main()
{
    string str = " ", in;
    int tot = 1;
    while (getline(cin, in))
    {
        if (!isdigit(in[0]) || !isdigit(str[pos[tot - 1] - 1]))
        {
            str += " ";
        }
        str += in;
        pos[tot++] = str.length();
    }

    int l = 0, r = 0, len = str.length();
    while (r < len)
    {
        while (str[r] == ' ')
        {
            r++;
        }
        l = r;
        while (str[r] != ' ')
        {
            r++;
        }
        string t = str.substr(l, r - l);
        long long num = check(t);
        if (num != -1)
        {
            int p = upper_bound(pos, pos + tot, l) - pos;
            cnt[p]++;
            cout << num << ' ';
        }
    }
    cout << endl;
    for (int i = 1; i < tot; i++)
    {
        cout << cnt[i] << endl;
    }
    return 0;
}