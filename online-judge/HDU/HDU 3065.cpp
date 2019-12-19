#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;

const int maxn = 500007;

int ans[1007];

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
        end[L++] = -1;
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

    void query(char buf[])
    {
        int len = strlen(buf);
        int now = root;
        for (int i = 0; i < len; i++)
        {
            now = next[now][buf[i]];
            int temp = now;
            while (temp != root)
            {
                if (end[temp] != -1)
                {
                    ans[end[temp]]++;
                }
                temp = fail[temp];
            }
        }
    }
} ac;

char pat[1007][60], str[2000007];

int main()
{
    int n, m;
    while (~scanf("%d", &n))
    {
        memset(ans, 0, sizeof(ans));
        ac.init();
        for (int i = 0; i < n; i++)
        {
            scanf("%s", pat[i]);
            ac.insert(pat[i], i);
        }
        ac.build();
        scanf("%s", str);
        ac.query(str);
        for (int i = 0; i < n; i++)
        {
            if (ans[i] > 0)
            {
                printf("%s: %d\n", pat[i], ans[i]);
            }
        }
    }
    return 0;
}
