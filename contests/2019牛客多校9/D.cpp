#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;

long long n, arr[40];
unsigned long long ans, s;
unordered_map<unsigned long long, unsigned long long> mp;

void dfs1(int pos, unsigned long long sum, unsigned long long sit)
{
    if (pos == n / 2 + 1)
    {
        mp[sum] = sit;
        return;
    }
    dfs1(pos + 1, sum + arr[pos], sit | (1LL << pos));
    dfs1(pos + 1, sum, sit);
}

void dfs2(int pos, unsigned long long sum, unsigned long long sit)
{
    if (ans)
        return;
    if (pos == n / 2)
    {
        unsigned long long tar = s - sum;
        if (mp.count(tar))
        {
            ans = mp[tar] | sit;
        }
        return;
    }
    dfs2(pos - 1, sum + arr[pos], sit | (1LL << pos));
    dfs2(pos - 1, sum, sit);
}

int main()
{
    cin >> n >> s;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    dfs1(1, 0, 0);
    dfs2(n, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        cout << ((ans >> i) & 1);
    }
    return 0;
}