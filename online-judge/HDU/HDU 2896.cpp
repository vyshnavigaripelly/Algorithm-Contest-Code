#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
#include <set>
using namespace std;

const int maxn = 500007;

struct Trie
{
    int next[maxn][130], fail[maxn], end[maxn];
    int root, L;

    int newnode()
    {
        for (int i = 0; i < 130; i++)
        {
            next[L][i] = -1;
        }
        end[L++] = 0;
        return L - 1;
    }

    void init()
    {
        L = 0;
        root = newnode();
    }

    void insert(char buf[], int pos)
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            if (next[now][buf[i]] == -1)
            {
                next[now][buf[i]] = newnode();
            }
            now = next[now][buf[i]];
        }
        end[now] = pos;
    }

    void build()
    {
        queue<int> Q;
        fail[root] = root;
        for (int i = 0; i < 130; i++)
        {
            if (next[root][i] == -1)
            {
                next[root][i] = root;
            }
            else
            {
                fail[next[root][i]] = root;
                Q.push(next[root][i]);
            }
        }
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int i = 0; i < 130; i++)
            {
                if (next[now][i] == -1)
                {
                    next[now][i] = next[fail[now]][i];
                }
                else
                {
                    fail[next[now][i]] = next[fail[now]][i];
                    Q.push(next[now][i]);
                }
            }
        }
    }

    set<int> query(char buf[])
    {
        set<int> ans;
        int len = strlen(buf);
        int now = root;

        for (int i = 0; i < len; i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while (temp != root)
            {
                if (end[temp] > 0)
                {
                    ans.insert(end[temp]);
                }
                // res += end[temp];
                // end[temp] = 0;
                temp = fail[temp];
            }
        }
        return ans;
    }
} ac;

char str[10007];

int main()
{
    int n, m;
    while (~scanf("%d", &n))
    {
        ac.init();
        for (int i = 1; i <= n; i++)
        {
            scanf("%s", str);
            ac.insert(str, i);
        }
        ac.build();
        scanf("%d", &m);
        int cnt = 0;
        for (int i = 1; i <= m; i++)
        {
            scanf("%s", str);
            set<int> ans = ac.query(str);
            if (ans.size() > 0)
            {
                printf("web %d:", i);
                for (auto k : ans)
                {
                    printf(" %d", k);
                }
                puts("");
                cnt++;
            }
        }
        printf("total: %d\n", cnt);
    }
    return 0;
}
