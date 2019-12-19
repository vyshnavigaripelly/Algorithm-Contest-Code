#include <iostream>
#include <bitset>
#include <map>
#include <vector>
#include <cstring>

using namespace std;

int a[70], b[70], cnt[3];
vector<int> posarr[3];

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(a, 0, sizeof(a));
        memset(b, 0, sizeof(b));
        memset(cnt, 0, sizeof(cnt));
        posarr[1].clear();
        posarr[2].clear();
        long long x;
        scanf("%lld", &x);
        if (x % 3 == 0)
        {
            printf("1 %lld\n", x);
            continue;
        }
        int pos = 0;
        while (x)
        {
            a[pos] = x & 1;
            if (a[pos])
            {
                b[pos] = (pos + 1) % 2 + 1;
                cnt[b[pos]]++;
                posarr[b[pos]].push_back(pos);
            }
            x >>= 1;
            pos++;
        }
        int mincnt, minnum;
        if (cnt[1] <= cnt[2])
        {
            minnum = 1;
        }
        else
        {
            minnum = 2;
        }
        mincnt = cnt[minnum];
        long long ans1 = 0, ans2 = 0;
        for (int i = 0; i < mincnt; i++)
        {
            ans1 |= (1LL << posarr[1][i]);
            ans1 |= (1LL << posarr[2][i]);
        }
        int maxnum = 3 - minnum, sum;
        if (mincnt == 0)
        {
            sum = posarr[maxnum].size() - mincnt;
            if (maxnum == 1)
            {
                int tmpp = sum, pos = 0;
                while (true)
                {

                    if (sum * 1 % 3 == 0)
                    {
                        break;
                    }
                    sum--;
                }
                for (int i = mincnt; i < sum - pos; i++)
                {
                    ans2 |= (1LL << posarr[maxnum][i]);
                }
                while (true)
                {

                    if ((tmpp - sum + 1) * 1 % 3 == 0)
                    {
                        break;
                    }
                    sum--;
                }
            }
            else
            {
                int tmpp = sum, pos = 0;
                while (true)
                {
                    if (sum * 2 % 3 == 0)
                    {
                        break;
                    }
                    sum--;
                }
                for (int i = mincnt; i < sum; i++)
                {
                    ans2 |= (1LL << posarr[maxnum][i]);
                }
                while (true)
                {
                    if ((tmpp - sum + 1) * 2 % 3 == 0)
                    {
                        break;
                    }
                    sum--;
                }
            }
        }
        else
        {
            sum = posarr[maxnum].size() - mincnt;
            sum *= maxnum;
            sum %= 3;
            for (int i = mincnt; i < posarr[maxnum].size(); i++)
            {
                ans2 |= (1LL << posarr[maxnum][i]);
            }
        }
        if (mincnt == 0 && sum != 0)
        {
            if (maxnum == 1)
            {
                for (int i = sum - 1; i < posarr[maxnum].size(); i++)
                {
                    ans1 |= (1LL << posarr[maxnum][i]);
                }
            }
            else
            {
                for (int i = sum - 1; i < posarr[maxnum].size(); i++)
                {
                    ans1 |= (1LL << posarr[maxnum][i]);
                }
            }
        }
        else
        {
            if (sum == 1)
            {
                ans2 |= (1LL << posarr[2][0]);
            }
            if (sum == 2)
            {
                ans2 |= (1LL << posarr[1][0]);
            }
        }
        printf("2 %lld %lld\n", ans1, ans2);
    }
    return 0;
}