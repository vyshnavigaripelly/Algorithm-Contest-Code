#include <iostream>

using namespace std;

long long minn = 0x3f3f3f3f3f3f3f3f, ans;
long long n, p2, p3;

void dfs(int p, long long now)
{
    if (p >= n)
    {
        minn = min(minn, now);
        return;
    }
    dfs(p + 2, now + p2);
    dfs(p + 3, now + p3);
}

int main()
{
    cin >> n >> p2 >> p3;
    long long v2 = 3 * p2, v3 = 2 * p3;
    n -= 6;
    if (n > 0)
    {
        if (v2 < v3)
        {
            ans += (n - n % 6) / 2 * p2;
        }
        else
        {
            ans += (n - n % 6) / 3 * p3;
        }
        n %= 6;
    }
    n += 6;
    dfs(0, 0);
    ans += minn;
    cout << ans << endl;
    return 0;
}