#include <iostream>
#include <map>
#include <vector>

using namespace std;

typedef pair<int, int> Point;

Point arr[20];
map<pair<pair<int, int>, int>, vector<int>> mp;

int calc(int i, int j)
{
    return (arr[i].first - arr[j].first) * (arr[i].first - arr[j].first) +
           (arr[i].second - arr[j].second) * (arr[i].second - arr[j].second);
}

int cross(Point a, Point b)
{
    return a.first * b.second - a.second * b.first;
}

// 1 - left, 2 - right, 3 - on line
int linerelation(int s, int e, int p)
{
    int c = cross(make_pair(arr[p].first - arr[s].first, arr[p].second - arr[s].second),
                  make_pair(arr[e].first - arr[s].first, arr[e].second - arr[s].second));
    if (c < 0)
        return 1;
    if (c > 0)
        return 2;
    return 3;
}

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        mp.clear();
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d", &arr[i].first, &arr[i].second);
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    int a = calc(i, j), b = calc(i, k), c = calc(j, k);
                    int minn = min(min(a, b), c);
                    int maxn = max(max(a, b), c);
                    int midn = a + b + c - minn - maxn;
                    int x, y, z;
                    if (minn == a)
                        x = i, y = j, z = k;
                    else if (minn == b)
                        x = i, y = k, z = j;
                    else
                        x = j, y = k, z = i;
                    if (linerelation(x, y, z) == 3)
                    {
                        continue;
                    }
                    if (linerelation(x, y, z) == 2)
                    {
                        swap(x, y);
                    }
                    a = calc(x, y);
                    b = calc(y, z);
                    c = calc(z, x);
                    int tmpa = a * 1000000 + b * 1000 + c,
                        tmpb = b * 1000000 + c * 1000 + a,
                        tmpc = c * 1000000 + a * 1000 + b;
                    int min2 = min(min(tmpa, tmpb), tmpc);
                    mp[make_pair(make_pair(min2 / 1000000, min2 / 1000 % 1000), min2 % 1000)].push_back(100 * x + 10 * y + z);
                }
            }
        }
        long long ans = 0;
        for (map<pair<pair<int, int>, int>, vector<int>>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            vector<int> &tmp = it->second;
            for (int i = 0; i < tmp.size(); i++)
            {
                for (int j = i + 1; j < tmp.size(); j++)
                {
                    int flag = 1;
                    int cnt[10] = {0};
                    int x = tmp[i], y = tmp[j];
                    if (x < 100)
                        cnt[0]++;
                    while (x > 0)
                    {
                        cnt[x % 10]++;
                        x /= 10;
                    }
                    if (y < 100)
                        cnt[0]++;
                    while (y > 0)
                    {
                        cnt[y % 10]++;
                        y /= 10;
                    }
                    for (int k = 0; k <= 9; k++)
                    {
                        if (cnt[k] > 1)
                        {
                            flag = 0;
                            break;
                        }
                    }
                    if (flag)
                    {
                        ans++;
                    }
                }
            }
        }
        printf("Case %d: %lld\n", cas, ans * 2);
    }
    return 0;
}