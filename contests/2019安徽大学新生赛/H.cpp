#include <bits/stdc++.h>

using namespace std;

long long minA = 0x3f3f3f3f3f3f3f3f;

void solve(long long cost, long long now)
{
    if (cost >= minA)
    {
        return;
    }
    if (now == 1)
    {
        minA = cost;
        return;
    }
    int flag = 0, x = sqrt(now);
    for (int i = 2; i <= x; i++)
    {
        if (now % i == 0)
        {
            flag = 1;
            solve(cost + i, now / i);
            break;
        }
    }
    if (!flag)
    {
        solve(cost + now, 1);
    }
}

int main()
{
    long long n;
    cin >> n;
    solve(0, n);
    cout << minA << endl;
    return 0;
}
