#include <iostream>
#include <queue>

using namespace std;

const int N = 3007;

long long arr[N][N], minn[N][N];
deque<int> que;

int main()
{
    long long n, m, a, b, g, x, y, z;
    scanf("%lld %lld %lld %lld %lld %lld %lld %lld", &n, &m, &a, &b, &g, &x, &y, &z);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            arr[i][j] = g;
            g = (g * x + y) % z;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        que.clear();
        for (int j = 1; j <= m; j++)
        {
            while (!que.empty() && arr[i][que.back()] >= arr[i][j])
                que.pop_back();
            while (!que.empty() && que.front() < j - b + 1)
                que.pop_front();
            que.push_back(j);
            if (j >= b)
                minn[i][j] = arr[i][que.front()];
        }
    }
    long long ans = 0;
    for (int j = b; j <= m; j++)
    {
        que.clear();
        for (int i = 1; i <= n; i++)
        {
            while (!que.empty() && minn[que.back()][j] >= minn[i][j])
                que.pop_back();
            while (!que.empty() && que.front() < i - a + 1)
                que.pop_front();
            que.push_back(i);
            if (i >= a)
                ans += minn[que.front()][j];
        }
    }
    printf("%lld\n", ans);
    return 0;
}