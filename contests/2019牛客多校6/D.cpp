#include <bits/stdc++.h>

using namespace std;

const int N = 2e4 + 7;

int n, k;
int arr[N];

int check(int v)
{
    list<int> lst;
    for (int i = 1; i <= n; i++)
    {
        lst.push_back(arr[i]);
    }
    int tmpk = k;
    while (tmpk-- && lst.size())
    {
        int res = v;
        for (auto it = lst.begin(); it != lst.end();)
        {
            if (*it <= res)
            {
                res -= *it;
                lst.erase(it++);
                if (!res)
                    break;
            }
            else
            {
                it++;
            }
        }
    }
    if (lst.empty())
        return 1;
    return 0;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int sum = 0;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        sort(arr + 1, arr + 1 + n, greater<int>());
        int l = arr[1], r = sum, ans = 0x3f3f3f3f;
        while (l <= r)
        {
            int mid = (l + r) >> 1;
            if (check(mid))
            {
                r = mid - 1;
                ans = min(ans, mid);
            }
            else
            {
                l = mid + 1;
            }
        }
        int now = ans;
        for (int i = 1; i <= 500; i++)
        {
            now--;
            if (check(now))
            {
                ans = now;
            }
        }
        printf("Case #%d: %d\n", cas, ans);
    }
    return 0;
}