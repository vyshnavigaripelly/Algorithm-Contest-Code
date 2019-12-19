#include <bits/stdc++.h>

using namespace std;

long long diff[30];
string str[100007];
unordered_map<string, pair<long long, long long>> mp; // <str, <diff, cnt>>

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < 26; i++)
    {
        scanf("%lld", &diff[i]);
    }
    for (int i = 0; i < n; i++)
    {
        cin >> str[i];
        long long sum = 1;
        for (int j = 0; j < str[i].length(); j++)
        {
            sum *= diff[str[i][j] - 'a'];
            sum %= m;
            string tmp = str[i].substr(0, j + 1);
            mp[tmp].first = sum;
            mp[tmp].second++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        long long ans = 0, difff = mp[str[i]].first;
        for (int j = 0; j < str[i].length() - 1; j++)
        {
            string tmp = str[i].substr(0, j + 1);
            if (mp[tmp].first > difff)
            {
                ans += mp[tmp].second;
            }
        }
        printf("%lld ", ans);
    }
    return 0;
}