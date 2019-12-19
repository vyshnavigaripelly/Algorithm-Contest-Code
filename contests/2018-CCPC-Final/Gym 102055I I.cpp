#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <cstring>

using namespace std;

const int N = (int)1e5 + 7;

struct Node
{
    int x, y;
} arr[N];

int disx[N], disy[N];
unordered_set<int> posx[N], posy[N];
unordered_set<int> ansx;
pair<int, int> cntx[N], cnty[N]; // count, pos
int que[N];
long long ans[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        memset(ans, 0, sizeof(ans));
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d %d", &arr[i].x, &arr[i].y);
            disx[i] = arr[i].x;
            disy[i] = arr[i].y;
        }
        sort(disx + 1, disx + 1 + n);
        sort(disy + 1, disy + 1 + n);
        int totx = unique(disx + 1, disx + 1 + n) - (disx + 1);
        int toty = unique(disy + 1, disy + 1 + n) - (disy + 1);
        for (int i = 1; i <= totx; i++)
        {
            posx[i].clear();
            cntx[i] = {0, 0};
        }
        for (int i = 1; i <= toty; i++)
        {
            posy[i].clear();
            cnty[i] = {0, 0};
        }
        for (int i = 1; i <= n; i++)
        {
            int tx = lower_bound(disx + 1, disx + 1 + totx, arr[i].x) - disx;
            int ty = lower_bound(disy + 1, disy + 1 + toty, arr[i].y) - disy;
            posx[tx].insert(ty);
            posy[ty].insert(tx);
            cntx[tx].first++;
            cnty[ty].first++;
        }
        set<int> vis;
        for (int i = 1; i <= totx; i++)
        {
            ans[cntx[i].first]++;
            vis.insert(cntx[i].first);
        }
        long long maxn = -1, num = -1, val = -1;
        for (int i = 1; i <= toty; i++)
        {
            int quecnt = 0;
            for (auto j : posy[i])
            {
                ans[cntx[j].first]--;
                if (ans[cntx[j].first] == 0)
                    vis.erase(cntx[j].first);
                ans[cntx[j].first - 1]++;
                vis.insert(cntx[j].first - 1);
            }
            long long tmp = *(--vis.end());
            tmp += cnty[i].first;
            if (tmp > val)
            {
                val = tmp;
                num = ans[*(--vis.end())];
            }
            else if (tmp == val)
            {
                num += ans[*(--vis.end())];
            }
            for (auto j : posy[i])
            {
                ans[cntx[j].first]++;
                vis.insert(cntx[j].first);
                ans[cntx[j].first - 1]--;
                if (ans[cntx[j].first - 1] == 0)
                    vis.erase(cntx[j].first - 1);
            }
        }
        if (val == 2)
            num /= 2;
        if (totx == 1 || toty == 1)
            num = 1;
        printf("Case %d: %lld %lld\n", cas, val, num);
    }
    return 0;
}