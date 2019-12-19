#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int v[10];

namespace fio
{
    const int MX = 4e7;
    char buf[MX];
    int c, sz;

    void fioinit()
    {
        c = 0;
        sz = fread(buf, 1, MX, stdin);
    }

    inline bool read(int &t)
    {
        while (c < sz && buf[c] != '-' && (buf[c] < '0' || buf[c] > '9'))
            c++;
        if (c >= sz)
            return false;
        bool flag = 0;
        if (buf[c] == '-')
            flag = 1, c++;
        for (t = 0; c < sz && '0' <= buf[c] && buf[c] <= '9'; c++)
            t = t * 10 + buf[c] - '0';
        if (flag)
            t = -t;
        return true;
    }
}

using namespace fio;

struct Monster
{
    int id, a[10], b[10], flag;
} mon[100007];

struct Attr
{
    int id, val;
} attr[10][100007];

int cmp(const Attr &a, const Attr &b)
{
    return a.val < b.val;
}

int main()
{
    fioinit();
    int t;
    read(t);
    while (t--)
    {
        int n, k;
        read(n);
        read(k);
        for (int i = 0; i < k; i++)
        {
            read(v[i]);
        }
        for (int i = 0; i < n; i++)
        {
            mon[i].flag = 0;
            mon[i].id = i;
            for (int j = 0; j < k; j++)
            {
                read(mon[i].a[j]);
                attr[j][i] = {.id = i, .val = mon[i].a[j]};
            }
            for (int j = 0; j < k; j++)
            {
                read(mon[i].b[j]);
            }
        }
        for (int i = 0; i < k; i++)
        {
            sort(attr[i], attr[i] + n, cmp);
        }
        int f = 1;
        for (int i = 0; i < k && f; i++)
        {
            if (v[i] < attr[i][0].val)
            {
                f = 0;
                puts("0");
                for (int j = 0; j < k; j++)
                {
                    printf("%d%c", v[i], " \n"[i == k - 1]);
                }
            }
        }
        if (f == 0)
        {
            continue;
        }
        int now[10] = {0}, ans = 0;
        while (true)
        {
            int cnt = 0;
            for (int i = 0; i < k; i++)
            {
                int j = now[i];
                while (v[i] >= attr[i][j].val && j < n)
                {
                    int nowid = attr[i][j].id;
                    mon[nowid].flag++;
                    if (mon[nowid].flag == k)
                    {
                        for (int jj = 0; jj < k; jj++)
                        {
                            v[jj] += mon[nowid].b[jj];
                        }
                        ans++;
                    }
                    cnt++;
                    j++;
                }
                now[i] = j;
            }
            if (cnt == 0)
            {
                break;
            }
        }
        printf("%d\n", ans);
        for (int i = 0; i < k; i++)
        {
            printf("%d%c", v[i], " \n"[i == k - 1]);
        }
    }
    return 0;
}