#include <iostream>

using namespace std;

const int N = 1e6 + 7;

long long presum[N], sufsum[N];

int main()
{
    string s;
    cin >> s;
    for (int i = 1; i < (int)s.length(); i++)
    {
        if (s[i] == s[i - 1] && s[i] == 'v')
        {
            presum[i]++;
        }
        presum[i] += presum[i - 1];
    }
    for (int i = (int)s.length() - 2; i >= 0; i--)
    {
        if (s[i] == s[i + 1] && s[i] == 'v')
        {
            sufsum[i]++;
        }
        sufsum[i] += sufsum[i + 1];
    }
    long long ans = 0;
    for (int i = 2; i < (int)s.length() - 2; i++)
    {
        if (s[i] == 'o')
        {
            ans += presum[i] * sufsum[i];
        }
    }
    cout << ans << endl;
    return 0;
}