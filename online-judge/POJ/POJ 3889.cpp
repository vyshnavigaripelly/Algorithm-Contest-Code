#include <iostream>
#include <map>
#include <cmath>
#include <cstdio>

using namespace std;

pair<long long, long long> calc(long long n, long long m)
{
    if (n == 0)
    {
        return make_pair(0, 0);
    }
    long long size = 1 << (n - 1), cnt = 1 << (2 * n - 2);
    pair<long long, long long> pos = calc(n - 1, m % cnt);
    long long idx = m / cnt;
    long long x = pos.first, y = pos.second;
    if (idx == 0)
    {
        return make_pair(y, size - 1 - (size - x - 1));
    }
    else if (idx == 1)
    {
        return make_pair(x, y + size);
    }
    else if (idx == 2)
    {
        return make_pair(x + size, y + size);
    }
    else if (idx == 3)
    {
        return make_pair(size + size - y - 1, size - x - 1);
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long n, a, b;
        scanf("%lld %lld %lld", &n, &a, &b);
        pair<long long, long long> posa = calc(n, a - 1), posb = calc(n, b - 1);
        printf("%.0f\n", 10 * sqrt((posa.first - posb.first) * (posa.first - posb.first) + (posa.second - posb.second) * (posa.second - posb.second)));
    }
    return 0;
}