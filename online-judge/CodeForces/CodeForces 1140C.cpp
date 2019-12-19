#include <iostream>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<long long, long long> pll;

pll p[300007];
priority_queue<pll, vector<pll>, greater<pll>> pq;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> p[i].second >> p[i].first;
    }
    sort(p, p + n);
    long long ans = 0, tmp = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        pq.push({p[i].second, p[i].first});
        tmp += p[i].second;
        while (pq.size() > k)
        {
            tmp -= pq.top().first;
            pq.pop();
        }
        ans = max(ans, tmp * p[i].first);
    }
    cout << ans << endl;
    return 0;
}