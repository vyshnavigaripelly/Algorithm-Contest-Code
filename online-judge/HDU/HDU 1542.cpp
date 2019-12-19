#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

#define lson root << 1
#define rson root << 1 | 1

const int maxn = 1000;

struct Line
{
    double l, r; // 左右端点横坐标
    double y; // 纵坐标
    int val;
    bool operator<(const Line &a) const
    {
        return y < a.y;
    }
};

struct Node
{
    int cover;
    double len;
};

map<double, int> hsh; // 离散化横坐标
map<int, double> rhsh;
Node seg[maxn << 2];

void Build(int l, int r, int root)
{
    seg[root].cover = 0;
    seg[root].len = 0;
    if (l == r)
        return;
    int m = (l + r) >> 1;
    Build(l, m, lson);
    Build(m + 1, r, rson);
}

void PushUp(int l, int r, int root)
{
    if (seg[root].cover > 0)
        seg[root].len = rhsh[r + 1] - rhsh[l]; // [l, r)
    else if (l == r)
        seg[root].len = 0;
    else // seg[root].cover == 0
        seg[root].len = seg[lson].len + seg[rson].len;
}

void Update(int L, int R, int val, int l, int r, int root)
{
    if (L <= l && R >= r)
    {
        seg[root].cover += val;
        PushUp(l, r, root);
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m)
        Update(L, R, val, l, m, lson);
    if (R > m)
        Update(L, R, val, m + 1, r, rson);
    PushUp(l, r, root);
}

int main()
{
    int n, cas = 0;
    while (~scanf("%d", &n) && n)
    {
        double x1, x2, y1, y2;
        vector<Line> arr;
        set<double> xval; // 横坐标去重
        while (n--)
        {
            scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
            arr.push_back({x1, x2, y1, 1});
            arr.push_back({x1, x2, y2, -1});
            xval.insert(x1);
            xval.insert(x2);
        }
        hsh.clear();
        rhsh.clear();
        int cnt = 0;
        for (auto &i : xval)
        {
            hsh[i] = ++cnt;
            rhsh[cnt] = i;
        }
        sort(arr.begin(), arr.end());
        Build(1, cnt, 1);
        double ans = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            Update(hsh[arr[i].l], hsh[arr[i].r] - 1, arr[i].val, 1, cnt, 1); // [l, r)
            ans += (arr[i + 1].y - arr[i].y) * seg[1].len;
        }
        printf("Test case #%d\n", ++cas);
        printf("Total explored area: %.2f\n\n", ans);
    }
    return 0;
}