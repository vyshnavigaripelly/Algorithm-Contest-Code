#include <iostream>
#include <unordered_set>
#include <ext/pb_ds/priority_queue.hpp>

using namespace std;
using namespace __gnu_pbds;

const int N = 1e5 + 7;
const double eps = 1e-6;

struct Node
{
    char name[15], color[15];
    int power;
} cards[N];

int n, ans;
unordered_set<string> name, color, insname, inqname[4];
__gnu_pbds::priority_queue<pair<int, string>> q[4], choice[4];

void dfs(int pos, double coef, int v)
{
    if (pos == 5)
    {
        double t = v * coef;
        v = t + eps;
        ans = max(ans, v);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        if (!choice[i].empty())
        {
            pair<int, string> pp = choice[i].top();
            queue<pair<int, string>> qq;
            qq.push(choice[i].top());
            choice[i].pop();
            while (insname.count(pp.second) && !choice[i].empty())
            {
                pp = choice[i].top();
                qq.push(choice[i].top());
                choice[i].pop();
            }
            if (!insname.count(pp.second))
            {
                insname.insert(pp.second);
                dfs(pos + 1, coef + i / 10.0, v + pp.first);
                insname.erase(pp.second);
            }
            while (!qq.empty())
            {
                choice[i].push(qq.front());
                qq.pop();
            }
        }
    }
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        ans = -(1 << 30);
        name.clear();
        color.clear();
        insname.clear();
        for (int i = 0; i < 4; i++)
        {
            q[i].clear();
            choice[i].clear();
            inqname[i].clear();
        }
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%s %s %d", cards[i].name, cards[i].color, &cards[i].power);
        }
        string tmp;
        for (int i = 0; i < 5; i++)
        {
            cin >> tmp;
            name.insert(tmp);
        }
        cin >> tmp;
        color.insert(tmp);
        for (int i = 0; i < n; i++)
        {
            int res = 0;
            if (name.count(cards[i].name))
                res++;
            if (color.count(cards[i].color))
                res += 2;
            q[res].push({cards[i].power, cards[i].name});
        }
        for (int i = 0; i < 4; i++)
        {
            while (!q[i].empty())
            {
                if (!inqname[i].count(q[i].top().second))
                {
                    inqname[i].insert(q[i].top().second);
                    choice[i].push(q[i].top());
                }
                q[i].pop();
            }
        }
        dfs(0, 1.0, 0);
        printf("%d\n", ans);
    }
    return 0;
}