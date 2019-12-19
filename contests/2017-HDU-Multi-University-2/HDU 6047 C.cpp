#include <iostream>
#include <queue>

using namespace std;

const int mod = 1e9 + 7;

long long a[250007];
priority_queue<pair<long long, long long>> pq; // val, pos
priority_queue<long long, vector<long long>, greater<long long>> b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n)
    {
        while (!pq.empty())
        {
            pq.pop();
        }
        while (!b.empty())
        {
            b.pop();
        }
        for (long long i = 1; i <= n; i++)
        {
            cin >> a[i];
            pq.push({a[i] - i, i});
        }
        for (long long i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            b.push(x);
        }
        long long ans = 0;
        long long cur = 1, last = n + 1;
        while (true)
        {
            if (last > 2 * n)
            {
                break;
            }
            cur = b.top();
            b.pop();
            while (pq.top().second < cur)
            {
                pq.pop();
            }
            ans = (ans + pq.top().first + mod) % mod;
            pq.push({pq.top().first - last, last});
            last++;
        }
        cout << ans << endl;
    }
    return 0;
}