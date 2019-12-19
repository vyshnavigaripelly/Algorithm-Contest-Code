#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

struct node
{
    int idx;
    double score;
    int rank;
} team[110];

int cmpScore(const node &a, const node &b)
{
    return a.score > b.score;
}

int cmpID(const node &a, const node &b)
{
    return a.idx < b.idx;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, q, c;
        double s;
        scanf("%d %d %lf %d", &n, &q, &s, &c);
        for (int i = 1; i <= n; i++)
        {
            team[i].score = s;
            team[i].idx = i;
            team[i].rank = 1;
        }

        while (c--)
        {
            int vis[110][110][20] = {0};

            // attack
            int a;
            scanf("%d", &a);
            while (a--)
            {
                int att, def, ser;
                scanf("%d %d %d", &att, &def, &ser);
                if (vis[att][def][ser] == 1)
                {
                    continue;
                }
                vis[att][def][ser] = 1;
            }
            for (int i = 1; i <= q; i++) // servers
            {
                for (int j = 1; j <= n; j++) // defender
                {
                    int cnt = 0;
                    for (int k = 1; k <= n; k++) // attacker
                    {
                        if (vis[k][j][i] == 1)
                        {
                            cnt++;
                        }
                    }
                    if (cnt == 0)
                    {
                        continue;
                    }
                    team[j].score -= n - 1;
                    for (int k = 1; k <= n; k++)
                    {
                        if (vis[k][j][i] == 1)
                        {
                            team[k].score += 1.0 * (n - 1) / cnt;
                        }
                    }
                }
            }

            // maintain
            for (int i = 1; i <= q; i++) // servers
            {
                vector<int> succ, fail;
                for (int j = 1; j <= n; j++) // defender
                {
                    int x;
                    scanf("%d", &x);
                    if (x == 1)
                    {
                        succ.push_back(j);
                    }
                    else
                    {
                        fail.push_back(j);
                    }
                }

                for (int j = 0; j < fail.size(); j++)
                {
                    team[fail[j]].score -= n - 1;
                }
                for (int j = 0; j < succ.size(); j++)
                {
                    team[succ[j]].score += 1.0 * (n - 1) * fail.size() / succ.size();
                }
            }

            // sort
            sort(team + 1, team + 1 + n, cmpScore);
            team[1].rank = 1;
            for (int pos = 2; pos <= n; pos++)
            {
                if (team[pos - 1].score - team[pos].score <= 1e-5)
                {
                    team[pos].rank = team[pos - 1].rank;
                }
                else
                {
                    team[pos].rank = pos;
                }
            }
            sort(team + 1, team + 1 + n, cmpID);

            // query
            int u;
            scanf("%d", &u);
            while (u--)
            {
                int want;
                scanf("%d", &want);
                printf("%.8lf %d\n", team[want].score, team[want].rank);
            }
        }
    }
    return 0;
}
