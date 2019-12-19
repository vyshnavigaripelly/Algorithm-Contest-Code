#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <cstdio>
#include <cstring>

using namespace std;

int n, cnt;
int in[47];
int apper[47][47];
string name[47];
vector<int> mp[47];

int pos(char str[])
{
    for (int i = 0; i < cnt; i++)
    {
        if (name[i] == str)
            return i;
    }
    return -1;
}

int solve()
{
    queue<int> q;
    int tmp[47], mmp = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (!in[i])
            q.push(i);
        tmp[i] = in[i];
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        mmp++;
        for (int i = 0; i < mp[u].size(); i++)
        {
            int v = mp[u][i];
            tmp[v]--;
            if (!tmp[v])
                q.push(v);
        }
    }
    if (mmp == cnt)
        return 0;
    return 1;
}

int main()
{
    while (~scanf("%d", &n))
    {
        int flag = 0;
        memset(apper, 0, sizeof(apper));
        memset(in, 0, sizeof(in));
        for (int i = 0; i <= 46; i++)
            mp[i].clear();
        cnt = 0;
        char str1[107], str2[107];
        int u, v;
        getchar();
        for (int i = 0; i < n; i++)
        {
            scanf("%s %s", str1, str2);
            u = pos(str1);
            v = pos(str2);
            if (!~u)
            {
                name[cnt] = str1;
                u = cnt++;
            }
            if (!~v)
            {
                name[cnt] = str2;
                v = cnt++;
            }
            if (!apper[u][v])
            {
                apper[u][v] = 1;
                in[v]++;
                mp[u].push_back(v);
            }
            if (!flag)
            {
                flag = solve();
                if (flag)
                    printf("%s %s\n", str1, str2);
            }
        }
        if (!flag)
            printf("0\n");
    }
    return 0;
}