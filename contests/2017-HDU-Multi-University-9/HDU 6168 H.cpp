#include <bits/stdc++.h>

using namespace std;

const int N = 1e7 + 7;

map<int, int> mp;
int arr[N];

int main()
{
    int n;
    while (~scanf("%d", &n))
    {
        mp.clear();
        for (int i = 1; i <= n; i++)
        {
            int q;
            scanf("%d", &q);
            mp[q]++;
        }
        int cnt = 0;
        auto it = mp.begin();
        arr[++cnt] = it->first;
        mp[arr[1]]--;
        while (it != mp.end())
        {
            while (it->second == 0 && it != mp.end())
                it++;
            arr[++cnt] = it->first;
            mp[arr[cnt]]--;
            for (int j = 1; j < cnt; j++)
            {
                mp[arr[j] + arr[cnt]]--;
            }
        }
        printf("%d\n", cnt - 1);
        for (int i = 1; i < cnt; i++)
        {
            printf("%d%c", arr[i], i != cnt - 1 ? ' ' : '\n');
        }
    }
    return 0;
}
