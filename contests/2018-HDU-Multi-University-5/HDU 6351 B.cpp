#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int k, len;
string tmp, ansmin, ansmax, ini;

void dfsmin(int pos, int t)
{
    if (pos == len || t == k)
    {
        ansmin = min(tmp, ansmin);
        return;
    }
    int p = pos, minn = tmp[pos];
    for (int i = pos + 1; i < len; i++)
    {
        if (tmp[i] < minn)
        {
            minn = tmp[i];
            p = i;
        }
    }
    if (tmp[p] != tmp[pos])
    {
        for (int i = pos; i < len; i++)
        {
            if (tmp[i] == minn)
            {
                swap(tmp[pos], tmp[i]);
                dfsmin(pos + 1, t + 1);
                swap(tmp[pos], tmp[i]);
            }
        }
    }
    else
        dfsmin(pos + 1, t);
}

void dfsmax(int pos, int t)
{
    if (pos == len || t == k)
    {
        ansmax = max(tmp, ansmax);
        return;
    }
    int p = pos, maxn = tmp[pos];
    for (int i = pos + 1; i < len; i++)
    {
        if (tmp[i] > maxn)
        {
            maxn = tmp[i];
            p = i;
        }
    }
    if (tmp[p] != tmp[pos])
    {
        for (int i = pos; i < len; i++)
        {
            if (tmp[i] == maxn)
            {
                swap(tmp[pos], tmp[i]);
                dfsmax(pos + 1, t + 1);
                swap(tmp[pos], tmp[i]);
            }
        }
    }
    else
        dfsmax(pos + 1, t);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> ini >> k;
        ansmin = ini, ansmax = ini;
        len = ini.size();
        tmp = ini;
        //防首0的特殊处理
        int p = 0;
        for (int i = 1; i < len; i++)
        {
            if (tmp[i] < tmp[p] && tmp[i] != '0')
                p = i;
        }
        if (!p)
            dfsmin(1, 0);
        else
        {
            for (int i = 1; i < len; i++)
            {
                if (tmp[i] == tmp[p])
                {
                    swap(tmp[i], tmp[0]);
                    dfsmin(1, 1);
                    swap(tmp[i], tmp[0]);
                }
            }
        }
        tmp = ini;
        dfsmax(0, 0);
        cout << ansmin << " " << ansmax << endl;
    }
    return 0;
}