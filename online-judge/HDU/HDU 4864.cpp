#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 100000 + 7;

struct Node
{
    int x, y;
} task[N], mac[N];

int cnt[107];

int cmp(const Node &a, const Node &b)
{
    return a.x > b.x || (a.x == b.x && a.y > b.y);
}

int main()
{
    int n, m;
    while (cin >> n >> m)
    {
        memset(cnt, 0, sizeof(cnt));
        for (int i = 0; i < n; i++)
        {
            cin >> mac[i].x >> mac[i].y;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> task[i].x >> task[i].y;
        }
        sort(mac, mac + n, cmp);
        sort(task, task + m, cmp);
        long long ans = 0, sum = 0;
        for (int i = 0, j = 0; i < m; i++)
        {
            while (j < n && mac[j].x >= task[i].x)
            {
                cnt[mac[j].y]++;
                j++;
            }
            for (int k = task[i].y; k <= 100; k++)
            {
                if (cnt[k] > 0)
                {
                    sum++;
                    ans += 500LL * task[i].x + 2 * task[i].y;
                    cnt[k]--;
                    break;
                }
            }
        }
        cout << sum << ' ' << ans << endl;
    }
    return 0;
}