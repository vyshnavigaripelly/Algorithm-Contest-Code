#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

const int maxn = 1e5 + 7;

long long cost[maxn], cnt[maxn];

priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> que;

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
        que.push(make_pair(cost[i], i));
    }
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
            while (!que.empty())
            {
                while (!que.empty() && cnt[que.top().second] == 0)
                {
                    que.pop();
                }
                if (que.empty())
                {
                    break;
                }
                auto now = que.top();
                if (cnt[now.second] >= num)
                {
                    cnt[now.second] -= num;
                    ans += now.first * num;
                    flag = 1;
                    break;
                }
                else
                {
                    ans += cnt[now.second] * now.first;
                    num -= cnt[now.second];
                    cnt[now.second] = 0;
                    que.pop();
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