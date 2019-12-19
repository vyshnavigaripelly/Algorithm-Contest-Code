#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool check(long long y, double x)
{
    if (x == floor(x))
    {
        long long x1 = (long long)floor(x);
        if (__gcd(x1 * x1, y * y) == 1 && x1 * x1 != y * y)
            return true;
    }
    return false;
}

set<pair<long long, long long>> solve(long long R)
{
    set<pair<long long, long long>> ans;
    for (long long d = 1; d <= sqrt(2 * R); d++)
    {
        if (2 * R % d == 0)
        {
            for (long long a = 1; a <= (long long)sqrt(2 * R / (2 * d)); a++)
            {
                double b = sqrt(((2 * R) / d) - a * a);
                if (check(a, b))
                {
                    long long x = b * b * d - R, y = sqrt(R * R - x * x);
                    ans.insert({x, y});
                    ans.insert({x, -y});
                    ans.insert({-x, y});
                    ans.insert({-x, -y});
                }
            }
            if (d != 2 * R / d)
            {
                long long d2 = 2 * R / d;
                for (long long a = 1; a <= (long long)sqrt(d / 2); a++)
                {
                    double b = sqrt(d - a * a);
                    if (check(a, b))
                    {
                        long long x = b * b * d2 - R, y = sqrt(R * R - x * x);
                        ans.insert({x, y});
                        ans.insert({x, -y});
                        ans.insert({-x, y});
                        ans.insert({-x, -y});
                    }
                }
            }
        }
    }
    ans.insert({0, R});
    ans.insert({0, -R});
    ans.insert({R, 0});
    ans.insert({-R, 0});
    return ans;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        set<pair<long long, long long>> aa = solve(a), bb = solve(b);
        set<pair<pair<long long, long long>, pair<long long, long long>>> ans;
        for (auto i : aa)
        {
            for (auto j : bb)
            {
                if ((i.first - j.first) * (i.first - j.first) + (i.second - j.second) * (i.second - j.second) == c * c)
                {
                    ans.insert({{i.first, i.second}, {j.first, j.second}});
                }
            }
        }
        printf("%d\n", ans.size());
        for (auto i : ans)
        {
            printf("%lld %lld %lld %lld\n", i.first.first, i.first.second, i.second.first, i.second.second);
        }
    }
    return 0;
}