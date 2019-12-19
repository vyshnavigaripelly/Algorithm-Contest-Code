#include <iostream>
#include <algorithm>

using namespace std;

struct Cow
{
    int minn, maxn, idx;
} cow[2700];

struct Bottle
{
    int val, cnt, idx;
} bot[2700];

int cmpcow(const Cow &a, const Cow &b)
{
    return a.minn > b.minn || (a.minn == b.minn && a.maxn > b.maxn);
}

int cmpbot(const Bottle &a, const Bottle &b)
{
    return a.val > b.val || (a.val == b.val && a.cnt > b.cnt);
}

int main()
{
    int c, l;
    cin >> c >> l;
    for (int i = 0; i < c; i++)
    {
        cin >> cow[i].minn >> cow[i].maxn;
        cow[i].idx = i;
    }
    for (int i = 0; i < l; i++)
    {
        cin >> bot[i].val >> bot[i].cnt;
        bot[i].idx = i;
    }
    sort(cow, cow + c, cmpcow);
    sort(bot, bot + l, cmpbot);
    int ans = 0;
    for (int i = 0; i < c; i++)
    {
        for (int j = 0; j < l; j++)
        {
            if (bot[j].cnt > 0 && bot[j].val >= cow[i].minn && bot[j].val <= cow[i].maxn)
            {
                ans++;
                bot[j].cnt--;
                break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}