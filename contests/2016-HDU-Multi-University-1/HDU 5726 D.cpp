#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

const int N = 1e5 + 7;

map<int, long long> cnt, gcd[N];
int arr[N];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct Node
    {
        int l, r;
        int gcd;
    } tr[N * 4];

    void pushup(int root)
    {
        tr[root].gcd = __gcd(tr[lson].gcd, tr[rson].gcd);
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 0};
        if (l == r)
        {
            tr[root].gcd = arr[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
        pushup(root);
    }

    int query(int root, int l, int r)
    {
        if (l <= tr[root].l && r >= tr[root].r)
            return tr[root].gcd;
        int mid = (tr[root].l + tr[root].r) >> 1;
        int ans = 0;
        if (l <= mid)
            ans = __gcd(ans, query(lson, l, r));
        if (r > mid)
            ans = __gcd(ans, query(rson, l, r));
        return ans;
    }
} seg;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        cnt.clear();
        for (auto &i : gcd)
        {
            i.clear();
        }
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            cnt[arr[i]]++;
            gcd[i][arr[i]]++;
            for (auto j : gcd[i - 1])
            {
                int g = __gcd(arr[i], j.first);
                gcd[i][g] += j.second;
                cnt[g] += j.second;
            }
        }
        seg.build(1, 1, n);
        printf("Case #%d:\n", cas);
        int q;
        scanf("%d", &q);
        while (q--)
        {
            int l, r;
            scanf("%d %d", &l, &r);
            int g = seg.query(1, l, r);
            printf("%d %lld\n", g, cnt[g]);
        }
    }
    return 0;
}