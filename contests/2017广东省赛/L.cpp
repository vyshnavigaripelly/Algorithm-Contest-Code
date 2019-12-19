#include <iostream>
#include <cstring>
#include <vector>
#include <map>
#include <string>

using namespace std;

map<string, vector<string>> mmp1;
map<string, int> vis;
map<string, string> mmp2;
vector<string> ans;

void dfs(string now)
{
    vis[now]++;
    int s = mmp1[now].size();
    for (int i = 0; i < s; i++)
    {
        string next = mmp1[now][i];
        if (vis.count(next))
            continue;
        if (mmp2[next] == "inline")
        {
            ans.push_back(next);
        }
        else
        {
            dfs(mmp2[next]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for (int cas = 1; cas <= t; cas++)
    {
        int n, k;
        string tmp, id, type, st;
        cin >> n;
        mmp1.clear();
        mmp2.clear();
        vis.clear();
        ans.clear();
        for (int i = 0; i < n; i++)
        {
            cin >> tmp >> k;
            if (i == 0)
                st = tmp;
            for (int j = 0; j < k; j++)
            {
                cin >> id >> type;
                if (type == "wrapper")
                    cin >> type;
                mmp1[tmp].push_back(id);
                mmp2[id] = type;
            }
        }
        dfs(st);
        int s = ans.size();
        cout << "Case #" << cas << ": ";
        for (int i = 0; i < s; i++)
        {
            cout << ans[i];
            if (i != (s - 1))
            {
                cout << " ";
            }
        }
        cout << endl;
    }
    return 0;
}