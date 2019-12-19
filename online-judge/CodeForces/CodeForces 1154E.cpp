#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct Node
{
    int pos, val, ans, l, r;
    bool operator<(const Node &a) const
    {
        return val < a.val;
    }
} arr[200007];

priority_queue<Node> pq;

int main()
{
    int n, k;
    scanf("%d %d", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i].val);
        arr[i].pos = i;
        arr[i].l = i - 1;
        arr[i].r = i + 1;
        pq.push(arr[i]);
    }
    arr[0].l = 0;
    arr[0].r = 1;
    arr[n + 1].l = n;
    arr[n + 1].r = n + 1;
    int flag = 1;
    while (!pq.empty())
    {
        Node now = pq.top();
        pq.pop();
        int pos = now.pos;
        arr[pos].ans = flag;
        arr[arr[pos].l].r = arr[pos].r;
        arr[arr[pos].r].l = arr[pos].l;
        for (int i = arr[pos].l, cnt = 0; i != 0 && cnt < k; i = arr[i].l)
        {
            arr[i].ans = flag;
            arr[arr[i].l].r = arr[i].r;
            arr[arr[i].r].l = arr[i].l;
            cnt++;
        }
        for (int i = arr[pos].r, cnt = 0; i != n + 1 && cnt < k; i = arr[i].r)
        {
            arr[i].ans = flag;
            arr[arr[i].l].r = arr[i].r;
            arr[arr[i].r].l = arr[i].l;
            cnt++;
        }
        while (!pq.empty() && arr[pq.top().pos].ans != 0)
        {
            pq.pop();
        }
        flag = flag % 2 + 1;
    }
    for (int i = 1; i <= n; i++)
    {
        printf("%d", arr[i].ans);
    }
    return 0;
}