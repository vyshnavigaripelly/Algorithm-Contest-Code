#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int maxn = 1e5 + 7;

long long cost[maxn], cnt[maxn];

struct Node
{
    long long cost;
    int idx;
} arr[maxn];

int cmp(const Node &a, const Node &b)
{
    return a.cost < b.cost || (a.cost == b.cost && a.idx < b.idx);
}

int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &cnt[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld", &cost[i]);
        arr[i] = {cost[i], i};
    }
    sort(arr + 1, arr + 1 + n, cmp);
    int cur = 1;
    for (int i = 1; i <= m; i++)
    {
        long long kind, num;
        scanf("%lld %lld", &kind, &num);
        long long ans = 0;
        if (cnt[kind] >= num)
        {
            cnt[kind] -= num;
            ans = cost[kind] * num;
        }
        else
        {
            int flag = 0;
            ans = cost[kind] * cnt[kind];
            num -= cnt[kind];
            cnt[kind] = 0;
            while (cur <= n)
            {
                while (cur <= n && cnt[arr[cur].idx] == 0)
                {
                    cur++;
                }
                if (cur > n)
                {
                    break;
                }
                Node now = arr[cur];
                if (cnt[now.idx] >= num)
                {
                    cnt[now.idx] -= num;
                    ans += now.cost * num;
                    flag = 1;
                    break;
                }
                else
                {
                    ans += cnt[now.idx] * now.cost;
                    num -= cnt[now.idx];
                    cnt[now.idx] = 0;
                    cur++;
                }
            }
            if (flag == 0)
            {
                ans = 0;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}