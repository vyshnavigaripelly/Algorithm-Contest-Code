#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const int N = 2810;
const int mod = 998857459;

int tot;
long long fac[N];
vector<pair<long long, int>> mp;

struct Node
{
    long long sum;
    int len;

    bool operator<(const Node &b) const
    {
        return sum < b.sum;
    }
} arr[N * N / 2];

struct SegTree
{
#define lson (root << 1)
#define rson (root << 1 | 1)

    struct SegNode
    {
        int l, r;
        int minn;
    } tr[N * N / 2 * 4];

    void pushup(int root)
    {
        tr[root].minn = min(tr[lson].minn, tr[rson].minn);
    }

    void build(int root, int l, int r)
    {
        tr[root] = {l, r, 1 << 30};
        if (l == r)
        {
            tr[root].minn = arr[l].len;
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
            return tr[root].minn;
        int mid = (tr[root].l + tr[root].r) >> 1;
        int ans = 1 << 30;
        if (l <= mid)
            ans = min(ans, query(lson, l, r));
        if (r > mid)
            ans = min(ans, query(rson, l, r));
        return ans;
    }

#undef lson
#undef rson
} seg;

int main()
{
    fac[1] = 1;
    for (int i = 2; i < N; i++)
    {
        fac[i] = fac[i - 1] * i % mod;
    }
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int k;
        scanf("%d", &k);
        if (k < 2803)
            mp.push_back({fac[k], i});
    }
    tot = 0;
    for (int i = 0; i < mp.size(); i++)
    {
        long long sum = mp[i].first % mod;
        arr[tot] = {sum, 1};
        tot++;
        for (int j = i + 1; j < mp.size(); j++)
        {
            sum += mp[j].first;
            sum %= mod;
            arr[tot] = {sum, mp[j].second - mp[i].second + 1};
            tot++;
        }
    }
    sort(arr + 1, arr + 1 + tot);
    seg.build(1, 1, tot);
    while (m--)
    {
        int k;
        scanf("%d", &k);
        int pos = lower_bound(arr + 1, arr + 1 + tot, (Node){k, 0}) - arr;
        if (pos == tot + 1)
        {
            puts("-1");
            continue;
        }
        int ans = seg.query(1, pos, tot);
        printf("%d\n", ans);
    }
    return 0;
}