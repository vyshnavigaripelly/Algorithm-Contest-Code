#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 100007;

long long first[N], last[N];

struct Machine
{
    long long ed, idx;
    bool operator<(const Machine &a) const
    {
        return a.ed < ed;
    }
};

struct Machine2
{
    long long ed, idx;
    bool operator<(const Machine2 &a) const
    {
        return a.ed > ed;
    }
};

struct Node
{
    long long st, ed;
} arr[N];

priority_queue<Machine> pq;
priority_queue<Machine2> avail;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        while (!pq.empty())
            pq.pop();
        while (!avail.empty())
            avail.pop();
        int n, tot = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%lld %lld", &arr[i].st, &arr[i].ed);
        }
        sort(arr, arr + n, [](const Node &a, const Node &b) {
            return a.st < b.st || (a.st == b.st && a.ed < b.ed);
        });
        for (int i = 0; i < n; i++)
        {
            while (pq.size() && pq.top().ed <= arr[i].st)
            {
                avail.push({last[pq.top().idx], pq.top().idx});
                pq.pop();
            }
            if (avail.empty())
            {
                tot++;
                pq.push({arr[i].ed, tot});
                last[tot] = arr[i].ed;
                first[tot] = arr[i].st;
            }
            else
            {
                auto tmp = avail.top();
                avail.pop();
                pq.push({arr[i].ed, tmp.idx});
                last[tmp.idx] = arr[i].ed;
            }
        }
        long long ans = 0;
        for (int i = 1; i <= tot; i++)
        {
            ans += last[i] - first[i];
        }
        printf("%d %lld\n", tot, ans);
    }
    return 0;
}