#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

const int dir[4][4] = {0, 1, -1, 0, 1, 0, 0, 1, -1, 0, 0, -1, 1, 0, 0, -1};

struct mys
{
    int x, y;
} point[16];

int n, m, cnt, maxt;
char mp[207][207];

int yes(mys a)
{
    if (a.x < 0 || a.x >= n || a.y < 0 || a.y >= m)
        return 1;
    if (mp[a.x][a.y] <= cnt)
        return 1;
    return 0;
}

int inrange(mys d)
{
    if (d.x > -1 && d.x < n && d.y > -1 && d.y < m)
        return 1;
    return 0;
}

int check(int cur)
{
    int vis[17] = {0}, flag = 1, c = 0;
    for (int i = 0; i < cnt; i++)
    {
        int now = (cur >> i) & 1;
        if (now)
        {
            mys d1, d2;
            d1.x = point[i].x + dir[0][0], d1.y = point[i].y + dir[0][1];
            d2.x = point[i].x + dir[0][2], d2.y = point[i].y + dir[0][3];
            if (yes(d1) && yes(d2))
            {
                vis[mp[point[i].x][point[i].y]]++;
                if (vis[mp[point[i].x][point[i].y]] == 1)
                    c++;
                if (inrange(d1))
                {
                    vis[mp[d1.x][d1.y]]++;
                    if (vis[mp[d1.x][d1.y]] == 1)
                        c++;
                }
                if (inrange(d2))
                {
                    vis[mp[d2.x][d2.y]]++;
                    if (vis[mp[d2.x][d2.y]] == 1)
                        c++;
                }
            }
        }
    }
    if (c == cnt)
        return 1;
    for (int i = 0; i < cnt; i++)
    {
        int now = (cur >> i) & 1;
        if (now)
        {
            mys d1, d2, d3, d4;
            int tmpc = c;
            d1.x = point[i].x + dir[0][0], d1.y = point[i].y + dir[0][1];
            d2.x = point[i].x + dir[0][2], d2.y = point[i].y + dir[0][3];
            if (yes(d1) && yes(d2))
            {
                vis[mp[point[i].x][point[i].y]]--;
                if (vis[mp[point[i].x][point[i].y]] == 0)
                    tmpc--;
                if (inrange(d1))
                {
                    vis[mp[d1.x][d1.y]]--;
                    if (vis[mp[d1.x][d1.y]] == 0)
                        tmpc--;
                }
                if (inrange(d2))
                {
                    vis[mp[d2.x][d2.y]]--;
                    if (vis[mp[d2.x][d2.y]] == 0)
                        tmpc--;
                }
            }
            for (int j = 1; j < 4; j++)
            {
                int tmpcc = tmpc;
                d3.x = point[i].x + dir[j][0], d3.y = point[i].y + dir[j][1];
                d4.x = point[i].x + dir[j][2], d4.y = point[i].y + dir[j][3];
                if (yes(d3) && yes(d4))
                {
                    vis[mp[point[i].x][point[i].y]]++;
                    if (vis[mp[point[i].x][point[i].y]] == 1)
                        tmpcc++;
                    if (inrange(d3))
                    {
                        vis[mp[d3.x][d3.y]]++;
                        if (vis[mp[d3.x][d3.y]] == 1)
                            tmpcc++;
                    }
                    if (inrange(d4))
                    {
                        vis[mp[d4.x][d4.y]]++;
                        if (vis[mp[d4.x][d4.y]] == 1)
                            tmpcc++;
                    }
                    if (tmpcc == cnt)
                        return 1;
                    vis[mp[point[i].x][point[i].y]]--;
                    if (inrange(d3))
                        vis[mp[d3.x][d3.y]]--;
                    if (inrange(d4))
                        vis[mp[d4.x][d4.y]]--;
                }
            }
            if (yes(d1) && yes(d2))
            {
                vis[mp[point[i].x][point[i].y]]++;
                if (inrange(d1))
                    vis[mp[d1.x][d1.y]]++;
                if (inrange(d2))
                    vis[mp[d2.x][d2.y]]++;
            }
        }
    }
    if (c != cnt)
        return 0;
    return 1;
}

int main()
{
    while (scanf("%d%d", &n, &m) && n && m)
    {
        int ans = 10000000;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            getchar();
            for (int j = 0; j < m; j++)
            {
                scanf("%c", &mp[i][j]);
                if (mp[i][j] == '.')
                {
                    point[cnt].x = i;
                    point[cnt].y = j;
                    mp[i][j] = cnt;
                    cnt++;
                }
            }
        }
        if (!cnt)
        {
            printf("0\n");
            continue;
        }
        maxt = 1 << cnt;
        while (--maxt)
        {
            if (check(maxt))
            {
                int tmp = maxt, tans = 0;
                while (tmp)
                {
                    tans += (tmp & 1);
                    tmp >>= 1;
                }
                ans = min(ans, tans);
            }
        }
        if (ans > 15)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}