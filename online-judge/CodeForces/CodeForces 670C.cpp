#include <iostream>
#include <map>

using namespace std;

int au[200007], su[200007];

map<int, int> cnt;

int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int k;
        scanf("%d", &k);
        cnt[k]++;
    }
    int m;
    scanf("%d", &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &au[i]);
    }
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &su[i]);
    }
    int maxau = 0, maxsu = 0, ans = 1;
    for (int i = 1; i <= m; i++)
    {
        if (cnt[au[i]] > maxau)
        {
            maxau = cnt[au[i]];
            maxsu = cnt[su[i]];
            ans = i;
        }
        else if (cnt[au[i]] == maxau && cnt[su[i]] > maxsu)
        {
            maxsu = cnt[su[i]];
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}