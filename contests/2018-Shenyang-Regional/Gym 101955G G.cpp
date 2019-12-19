#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <map>

using namespace std;

const int dir[4][2] = {{-1, -1}, {-1, 1}, {1, -1}, {1, 1}};

int mp[6007][6007];
vector<pair<int, int>> table[10000007], p;

int check(int x, int y)
{
    return x >= 1 && x <= 6000 && y >= 1 && y <= 6000;
}

int main()
{
    for (int i = 0; i <= 6000; i++)
    {
        for (int j = 0; j <= 6000; j++)
        {
            int d = i * i + j * j;
            if (d > (int)1e7)
            {
                break;
            }
            table[d].push_back({i, j});
        }
    }

    int t;
    scanf("%d", &t);
    for (int cas = 1; cas <= t; cas++)
    {
        int n, m, x, y, k, w, op;
        scanf("%d %d", &n, &m);
        for (int i = 0; i < n; i++)
        {
            scanf("%d %d %d", &x, &y, &w);
            mp[x][y] = w;
            p.push_back({x, y});
        }
        long long lastans = 0;
        printf("Case #%d:\n", cas);
        while (m--)
        {
            scanf("%d %d %d", &op, &x, &y);
            x = (x + lastans) % 6000 + 1;
            y = (y + lastans) % 6000 + 1;
            if (op == 1)
            {
                scanf("%d", &w);
                mp[x][y] = w;
                p.push_back({x, y});
            }
            else if (op == 2)
            {
                mp[x][y] = 0;
            }
            else if (op == 3)
            {
                set<pair<int, int>> se;
                scanf("%d %d", &k, &w);
                for (auto i : table[k])
                {
                    for (auto j : dir)
                    {
                        int xx = x + j[0] * i.first,
                            yy = y + j[1] * i.second;
                        if (check(xx, yy) && mp[xx][yy] != 0)
                        {
                            se.insert({xx, yy});
                        }
                    }
                }
                for (auto i : se)
                {
                    mp[i.first][i.second] += w;
                }
            }
            else
            {
                long long ans = 0;
                set<pair<int, int>> se;
                scanf("%d", &k);
                for (auto i : table[k])
                {
                    for (auto j : dir)
                    {
                        int xx = x + j[0] * i.first,
                            yy = y + j[1] * i.second;
                        if (check(xx, yy) && mp[xx][yy] != 0)
                        {
                            se.insert({xx, yy});
                        }
                    }
                }
                for (auto i : se)
                {
                    ans += mp[i.first][i.second];
                }
                printf("%lld\n", lastans = ans);
            }
        }
        for (auto i : p)
        {
            mp[i.first][i.second] = 0;
        }
        p.clear();
    }
    return 0;
}