#include <bits/stdc++.h>

using namespace std;

const int N = 1000 + 10;

int a[N][N], n, m;
int sta[N], tot, l[N], r[N];
int arr[N * N], cnt;
char s[N];
map<tuple<int, int, int>, int> mp;

int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%s", s + 1);
        for (int j = 1; j <= m; j++)
        {
            if (s[j] == '1')
            {
                a[i][j] = 1;
                a[i][j] += a[i][j - 1];
            }
        }
    }
    int ans = 0, st, ed;
    vector<int> anss = {0};
    for (int j = 1; j <= m; j++)
    {
        tot = st = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j] == 0)
                tot = 0, st = i;
            else
            {
                while (tot && a[sta[tot]][j] >= a[i][j])
                    tot--;
                if (tot == 0)
                    l[i] = st;
                else
                    l[i] = sta[tot];
                sta[++tot] = i;
            }
        }
        tot = 0, ed = n + 1;
        for (int i = n; i >= 1; i--)
        {
            if (a[i][j] == 0)
                tot = 0, ed = i;
            else
            {
                while (tot && a[sta[tot]][j] >= a[i][j])
                    tot--;
                if (tot == 0)
                    r[i] = ed;
                else
                    r[i] = sta[tot];
                sta[++tot] = i;
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (a[i][j])
            {
                mp[make_tuple(j, l[i], r[i] - 1)] = a[i][j] * (r[i] - l[i] - 1);
                anss.push_back((a[i][j] - 1) * (r[i] - l[i] - 1));
                anss.push_back(a[i][j] * (r[i] - l[i] - 2));
            }
        }
    }
    for (auto i : mp)
    {
        anss.push_back(i.second);
    }
    sort(anss.rbegin(), anss.rend());
    printf("%d\n", anss[1]);
    return 0;
}