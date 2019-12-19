#include <iostream>
#include <cstring>
#include <algorithm>
#include <queue>

using namespace std;

const int N = 1e5 + 7;

priority_queue<int> def;
int arr[N], brr[N], used[N], normal[N];

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m, flag, cnt = 0;
        scanf("%d %d", &n, &m);
        memset(used, 0, (n + 1) * sizeof(int));
        while (def.size())
            def.pop();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &brr[i]);
        }
        for (int i = 1; i <= m; i++)
        {
            scanf("%d", &flag);
            if (flag)
            {
                def.push(brr[i]);
            }
            else
            {
                normal[++cnt] = brr[i];
            }
        }
        sort(arr + 1, arr + 1 + n);
        sort(normal + 1, normal + 1 + cnt);
        int l = 1, r = n;
        long long tmpans1 = 0, tmpans2 = 0, ans = -1;
        while (def.size() && l <= n)
        {
            int now = def.top();
            def.pop();
            while (l <= n)
            {
                if (arr[l] < now || used[l])
                    l++;
                else
                {
                    used[l] = 1;
                    break;
                }
            }
        }
        // 防御怪打不完 || 防御怪打的完,但是不打
        int ll = 1;
        while (ll <= cnt && r > 0)
        {
            int now = normal[ll];
            ll++;
            if (arr[r] < now)
                break;
            tmpans1 += (arr[r] - now);
            r--;
        }
        ans = max(ans, tmpans1);
        if (l <= n) // 防御怪打得完，并且打了
        {
            l = 1, r = n;
            while (l <= cnt && r > 0)
            {
                int now = normal[l];
                l++;
                while (used[r])
                    r--;
                if (arr[r] < now)
                    break;
                tmpans2 += (arr[r] - now);
                r--;
            }
            if (l > cnt) //所有怪都打完了 剩下的打脸
            {
                while (r > 0)
                {
                    while (used[r])
                        r--;
                    tmpans2 += arr[r];
                    r--;
                }
            }
            ans = max(ans, tmpans2);
        }
        printf("Case %d: %lld\n", cas, ans);
    }
    return 0;
}
