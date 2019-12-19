#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    int cur = 0, ans = 0;
    char last = s[0];
    s += '#';
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] != last)
        {
            int len = i - 1 - cur + 1;
            char after;
            if (len % 2 == 1)
            {
                ans += len / 2;
                if (last == 'R')
                {
                    after = 'G';
                }
                else if (last == 'G')
                {
                    after = 'B';
                }
                else // B
                {
                    after = 'R';
                }
                for (int j = cur; j < i; j++)
                {
                    if ((j - cur) % 2 == 1)
                    {
                        s[j] = after;
                    }
                }
            }
            else
            {
                ans += len / 2;
                if (s[i] == 'R')
                {
                    after = (last == 'G' ? 'B' : 'G');
                }
                else if (s[i] == 'G')
                {
                    after = (last == 'B' ? 'R' : 'B');
                }
                else // B
                {
                    after = (last == 'R' ? 'G' : 'R');
                }
                for (int j = cur; j < i; j++)
                {
                    if ((j - cur) % 2 == 1)
                    {
                        s[j] = after;
                    }
                }
            }
            last = s[i];
            cur = i;
        }
    }
    cout << ans << endl;
    cout << s.substr(0, n) << endl;
    return 0;
}