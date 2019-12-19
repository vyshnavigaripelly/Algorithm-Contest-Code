#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct person
{
    int pos, v, id; //初始位置，速度，选手id
} p[100007];

struct
{ //存储每位选手左右是哪位
    int l, r;
} lr[100007];

struct node
{
    double t; //相遇时间
    int x, y; //相遇的两个选手的id
    bool operator<(const node a) const
    {
        return a.t < t;
    }
    node(double t, int x, int y) : t(t), x(x), y(y) {}
};

priority_queue<node> q;
bool kia[100007];
int n, L;

int cmp1(const person &a, const person &b)
{
    return a.pos < b.pos;
}

int cmp2(const person &a, const person &b)
{
    return a.id < b.id;
}

int gcd(int a, int b)
{
    if (!b)
        return a;
    return gcd(b, a % b);
}

double fun(int x, int y, int flag = 0)
{
    int dx = ((p[y].pos - p[x].pos) % L + L) % L;
    int dv = p[x].v - p[y].v;
    if (dv < 0)
    {
        dv = -dv;
        dx = L - dx;
    }
    if (flag)
    {
        int GCD = gcd(dx, dv);
        dx /= GCD, dv /= GCD;
        printf("%d/%d\n", dx, dv);
        return 1.0;
    }
    return 1.0 * dx / dv;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &n, &L);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i].pos);
            p[i].id = i;
            kia[i] = 0;
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &p[i].v);
        }
        sort(p + 1, p + 1 + n, cmp1);
        lr[p[1].id].l = p[n].id, lr[p[1].id].r = p[2].id;
        for (int i = 2; i < n; i++)
        {
            lr[p[i].id].l = p[i - 1].id;
            lr[p[i].id].r = p[i + 1].id;
        }
        lr[p[n].id].l = p[n - 1].id, lr[p[n].id].r = p[1].id;
        q.push(node(fun(1, n), p[1].id, p[n].id));
        for (int i = 1; i < n; i++)
        {
            q.push(node(fun(i, i + 1), p[i].id, p[i + 1].id));
        }
        sort(p + 1, p + 1 + n, cmp2);
        int cnt = 0;
        while (q.size() > 1)
        {
            node now = q.top();
            q.pop();
            if (kia[now.x] || kia[now.y])
                continue;
            if ((lr[now.x].l == now.y && lr[now.x].r == now.y) || (lr[now.y].l == now.y && lr[now.x].r == now.x))
                break;
            int killer = max(now.x, now.y), killed = now.x + now.y - killer, next;
            kia[killed] = 1;
            if (lr[killer].l == killed) //击杀者的左边是被杀者，向左寻找
            {
                lr[killer].l = lr[killed].l;
                lr[lr[killed].l].r = killer;
                next = lr[killed].l;
            }
            else //击杀者的右边是被杀者，向右寻找
            {
                lr[killer].r = lr[killed].r;
                lr[lr[killed].r].l = killer;
                next = lr[killed].r;
            }
            q.push(node(fun(killer, next), killer, next));
            if (++cnt >= n)
                break;
        }
        fun(q.top().x, q.top().y, 1);
        while (q.size())
            q.pop();
    }
    return 0;
}