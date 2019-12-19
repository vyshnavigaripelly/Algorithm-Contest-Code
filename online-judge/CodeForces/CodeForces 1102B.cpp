#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

map<int, int> mp;

struct Node
{
    int pos, val, col;
} arr[100007];

bool cmppos(const Node &a, const Node &b)
{
    return a.pos < b.pos;
}

bool cmpval(const Node &a, const Node &b)
{
    if (a.val != b.val)
    {
        return a.val < b.val;
    }
    return a.pos < b.pos;
}

int main()
{
    int k, n, maxn = -1;
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].val;
        arr[i].pos = i;
        mp[arr[i].val]++;
        maxn = max(mp[arr[i].val], maxn);
    }
    if (maxn > k)
    {
        cout << "NO" << endl;
    }
    else
    {
        cout << "YES" << endl;
        sort(arr + 1, arr + 1 + n, cmpval);
        int cnt = 1;
        for (int i = 1; i <= n; i++)
        {
            arr[i].col = cnt;
            cnt++;
            if (cnt > k)
            {
                cnt = 1;
            }
        }
        sort(arr + 1, arr + 1 + n, cmppos);
        for (int i = 1; i <= n; i++)
        {
            cout << arr[i].col << ' ';
        }
    }
    return 0;
}
