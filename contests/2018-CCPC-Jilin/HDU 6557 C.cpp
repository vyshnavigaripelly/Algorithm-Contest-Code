#include <iostream>
#include <cstring>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e6 + 7;

vector<int> num[N];
unordered_map<int, int> rk;
int n, cnt, flag[N], arr[N], ok;

int solve(int now, long long res)
{
    while (now <= n)
    {
        int SIZE = (rk.count(now) ? num[rk[now]].size() : 0);
        if (SIZE >= res)
        {
            for (int i = 0; i < res; i++)
            {
                flag[num[rk[now]][i]] = 1;
            }
            return 1;
        }
        long long tmp = res - SIZE;
        for (int i = 0; i < SIZE; i++)
        {
            flag[num[rk[now]][i]] = 1;
        }
        res = tmp * 2;
        now++;
        if (res > n)
        {
            return 0;
        }
    }
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        rk.clear();
        cnt = 0;
        scanf("%d", &n);
        for (int i = 0; i <= n + 5; i++)
        {
            num[i].clear();
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            if (!rk.count(arr[i]))
            {
                rk[arr[i]] = ++cnt;
                num[cnt].push_back(i);
            }
            else
                num[rk[arr[i]]].push_back(i);
        }
        ok = solve(1, 2LL);
        printf("Case %d: ", cas);
        if (!ok)
        {
            printf("NO\n");
        }
        else
        {
            memset(flag, 0, (n + 1) * sizeof(int));
            ok = solve(1, 1LL);
            printf("YES\n");
            for (int i = 1; i <= n; i++)
            {
                printf("%d", flag[i]);
            }
            puts("");
        }
    }
    return 0;
}