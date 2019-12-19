#include <iostream>
#include <queue>

using namespace std;

struct node
{
    double ini, now;
    int w;
    bool operator<(const node &a) const
    {
        return now < a.now;
    }
};

priority_queue<node> q;

int main()
{
    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        double tmp, sum = 0, avg, ans = 0;
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%lf", &tmp);
            q.push({tmp, tmp, 1});
            sum += tmp;
        }
        m -= n;
        while (m--)
        {
            node now = q.top();
            q.pop();
            sum -= now.now;
            now.now = tmp / (now.w + 1);
            now.w++;
            sum += now.now;
            q.push(now);
        }
        avg = sum / n;
        while (!q.empty())
        {
            node now = q.top();
            q.pop();
            ans = ans + (now.now - avg) * (now.now - avg) / n;
        }
        printf("%.9f\n", ans);
    }
    return 0;
}