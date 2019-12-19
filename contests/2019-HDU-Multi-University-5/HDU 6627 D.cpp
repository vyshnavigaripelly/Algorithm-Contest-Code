#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

const int N = 1e5 + 7;

struct Node
{
    double pos;
    long long k, b;
    long long fenzi, fenmu;

    void tofraction()
    {
        long long g = __gcd(k, b);
        fenzi = b / g;
        fenmu = k / g;
    }
} arr[N];

long long sumk[N], sumb[N], sum[N];
vector<pair<long long, long long>> ans, anss;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ans.clear();
        anss.clear();
        long long n, c;
        scanf("%lld %lld", &n, &c);
        sumk[0] = sumb[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            sumk[i] = sumb[i] = 0;
            scanf("%lld %lld", &arr[i].k, &arr[i].b);
            arr[i].pos = -1.0 * arr[i].b / arr[i].k;
            arr[i].tofraction();
            sumk[0] -= arr[i].k;
            sumb[0] -= arr[i].b;
        }
        sumk[n + 1] = sumk[n + 2] = sumb[n + 1] = sumb[n + 2] = 0;
        sort(arr + 1, arr + 1 + n, [](const Node &a, const Node &b) {
            return a.pos < b.pos;
        });
        for (int i = 1; i <= n; i++)
        {
            sumk[i] = sumk[i - 1];
            sumb[i] = sumb[i - 1];
            sumk[i] += arr[i].k * 2;
            sumb[i] += arr[i].b * 2;
        }
        if (1.0 * (c - sumb[0]) / sumk[0] <= arr[1].pos)
        {
            ans.push_back({c - sumb[0], sumk[0]});
        }
        if (1.0 * (c - sumb[n]) / sumk[n] >= arr[n].pos)
        {
            ans.push_back({c - sumb[n], sumk[n]});
        }
        int infflag = 0;
        for (int i = 1; i <= n - 1; i++)
        {
            if (sumk[i] == 0 && c == sumb[i])
            {
                infflag = 1;
                break;
            }
            else
            {
                double yl = arr[i].pos * sumk[i] + sumb[i],
                       yr = arr[i + 1].pos * sumk[i] + sumb[i];
                double x = 1.0 * (c - sumb[i]) / sumk[i];
                if (x >= arr[i].pos && x <= arr[i + 1].pos)
                {
                    ans.push_back({c - sumb[i], sumk[i]});
                }
            }
        }
        if (infflag)
        {
            puts("-1");
        }
        else
        {
            for (auto i : ans)
            {
                long long g = __gcd(i.first, i.second);
                long long a = i.first / g, b = i.second / g;
                if ((a < 0 && b < 0) || (b < 0 && a >= 0))
                {
                    a = -a;
                    b = -b;
                }
                anss.push_back({a, b});
            }
            sort(anss.begin(), anss.end(), [](const pair<long long, long long> &a, const pair<long long, long long> &b) {
                return a.first * b.second < a.second * b.first;
            });
            int tot = unique(anss.begin(), anss.end()) - anss.begin();
            printf("%d", tot);
            for (int i = 0; i < tot; i++)
            {
                printf(" %lld/%lld", anss[i].first, anss[i].second);
            }
            puts("");
        }
    }
    return 0;
}