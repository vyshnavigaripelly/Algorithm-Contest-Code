#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

set<int> st;
int vis[N], ans[N], arr[N], nxt[N];

void dfs(int u)
{
    vis[u] = 1;
    ans[u] = 1;
    if (nxt[u])
    {
        if (!vis[nxt[u]])
            dfs(nxt[u]);
        ans[u] += ans[nxt[u]];
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        st.clear();
        memset(nxt, 0, sizeof(nxt));
        memset(vis, 0, sizeof(vis));
        memset(ans, 0, sizeof(ans));
        int n, k;
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        int mid = 1;
        int l = max(1, mid - k), r = min(n, mid + k);
        for (int i = l; i <= r; i++)
        {
            st.insert(arr[i]);
        }
        auto it = st.find(arr[mid]);
        if (it != st.begin())
        {
            it--;
            nxt[arr[mid]] = *it;
        }
        int nowl = l, nowr = r;
        while (++mid <= n)
        {
            l = max(l, mid - k), r = min(n, mid + k);
            if (l > nowl)
            {
                st.erase(arr[nowl]);
                nowl++;
            }
            if (r > nowr)
            {
                st.insert(arr[r]);
                nowr++;
            }
            auto it = st.find(arr[mid]);
            if (it != st.begin())
            {
                it--;
                nxt[arr[mid]] = *it;
            }
        }
        for (int i = n; i >= 1; i--)
        {
            if (!vis[i])
                dfs(i);
        }
        for (int i = 1; i <= n; i++)
        {
            printf("%d", ans[i]);
            if (i != n)
                printf(" ");
        }
        puts("");
    }
    return 0;
}
