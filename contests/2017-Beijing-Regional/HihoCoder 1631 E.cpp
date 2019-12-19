#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct node
{
    int ed, c;
    bool operator<(const node &a) const
    {
        if (a.ed == ed)
        {
            return a.c < c;
        }
        return a.ed < ed;
    }
    node(int ed, int c) : ed(ed), c(c) {}
};

priority_queue<node> q;

int main()
{
    int n, m, x;
    while (~scanf("%d%d%d", &m, &n, &x))
    {
        if (x == 0)
        {
            printf("0 0\n");
            continue;
        }
        int arr[107];
        while (q.size())
            q.pop();
        int incomplete = min(n, m);
        m -= incomplete;
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        for (int i = 0; i < incomplete; i++)
        {
            q.push(node(arr[i], arr[i]));
        }
        int flag = 0;
        while (q.size())
        {
            node now = q.top();
            q.pop();
            if (now.ed == x)
            {
                incomplete--;
                while (q.size() && q.top().ed == x)
                {
                    q.pop();
                    incomplete--;
                }
                printf("%d %d\n", m, incomplete);
                flag = 1;
                break;
            }
            if (now.ed > x)
            {
                printf("%d %d\n", m, incomplete);
                flag = 1;
                break;
            }
            incomplete--;
            if (m)
            {
                m--;
                incomplete++;
                q.push(node(now.ed + now.c, now.c));
            }
        }
        if (!flag)
        {
            printf("%d %d\n", 0, 0);
        }
    }
    return 0;
}