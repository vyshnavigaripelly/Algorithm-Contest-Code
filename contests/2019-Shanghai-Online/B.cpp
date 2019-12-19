#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e3 + 5;

int arr[maxn], len;

int main()
{
    int t, cas = 0;
    scanf("%d", &t);
    while (t--)
    {
        memset(arr, 0, sizeof(arr));
        len = 0;
        int n, m;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < m; i++)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            arr[len++] = l;
            arr[len++] = r + 1;
        }
        sort(arr, arr + len);
        int ans = 0;
        for (int i = 0; i < len; i += 2)
        {
            ans += arr[i + 1] - arr[i];
        }
        printf("Case #%d: %d\n", ++cas, ans);
    }
    return 0;
}