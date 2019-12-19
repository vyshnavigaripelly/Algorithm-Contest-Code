#include <iostream>
#include <unordered_map>
#include <stack>
#include <algorithm>
#include <vector>

using namespace std;

int n, k, cnt;
unordered_map<int, int> bitnum;

struct node
{
    long long seq, ini;

    bool operator<(const node &a) const
    {
        return a.seq > seq;
    }
} ans[100007];

namespace Cantor
{
    const int N = 100;
    int fac[N];
    void init()
    {
        fac[0] = 1;
        for (int i = 1; i < N; ++i)
            fac[i] = fac[i - 1] * i;
    }

    int encode(int *a, int n)
    {
        int ret = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            int cnt = 0;
            for (int j = i + 1; j < n; ++j)
                if (a[j] < a[i])
                    ++cnt;
            ret += cnt * fac[n - 1 - i];
        }
        return ret;
    }

    vector<int> decode(int x, int n)
    {
        vector<int> ret;
        vector<int> v;
        for (int i = 1; i <= n; ++i)
            v.push_back(i);
        for (int i = n - 1; i >= 0; --i)
        {
            ret.push_back(v[x / fac[i]]);
            v.erase(v.begin() + x / fac[i]);
            x %= fac[i];
        }
        return ret;
    }
}

void dfs(long long tmp, long long seq, int last, int len, int choice)
{
    if (len == n)
    {
        ans[cnt].ini = tmp;
        ans[cnt++].seq = seq;
        return;
    }
    int tmpchoice = choice;
    while (tmpchoice)
    {
        int lowbit = tmpchoice & -tmpchoice;
        int num = bitnum[lowbit];
        long long nexttmp = tmp * 10 + num, nextseq = 0;
        int nextlast = num;
        if (len > 0)
        {
            nextseq = seq * 18 + (num - last) + 9;
        }
        dfs(nexttmp, nextseq, nextlast, len + 1, choice - lowbit);
        tmpchoice -= lowbit;
    }
}

int main()
{
    int num = 1, now = 0;
    while (now <= 10)
    {
        bitnum[num] = now + 1;
        now++;
        num <<= 1;
    }
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        cnt = 0;
        if (n <= 8)
        {
            int tar = 1;
            for (int i = 0; i < n - 1; i++)
            {
                tar <<= 1;
                tar |= 1;
            }
            dfs(0, 0, -1, 0, tar);
            sort(ans, ans + cnt);
            long long finalans = ans[k - 1].ini;
            stack<int> stk;
            while (finalans)
            {
                stk.push(finalans % 10);
                finalans /= 10;
            }
            while (stk.size())
            {
                cout << stk.top();
                stk.pop();
                if (stk.size())
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        else if (n == 9)
        {
            int first = 9, second = 1;
            int tar = 0;
            for (int i = 0; i < n; i++)
            {
                if (!(i + 1 == second || i + 1 == first))
                    tar |= (1 << i);
            }
            dfs(91, 1, 1, 2, tar);

            first = 9, second = 2;
            tar = 0;
            for (int i = 0; i < n; i++)
            {
                if (!(i + 1 == second || i + 1 == first))
                    tar |= (1 << i);
            }
            dfs(92, 2, 2, 2, tar);
            first = 8, second = 1;
            tar = 0;
            for (int i = 0; i < n; i++)
            {
                if (!(i + 1 == second || i + 1 == first))
                    tar |= (1 << i);
            }
            dfs(81, 2, 1, 2, tar);
            sort(ans, ans + cnt);
            long long finalans = ans[k - 1].ini;
            stack<int> stk;
            while (finalans)
            {
                stk.push(finalans % 10);
                finalans /= 10;
            }
            while (stk.size())
            {
                cout << stk.top();
                stk.pop();
                if (stk.size())
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
        else
        {
            Cantor::init();
            int arr[30];
            for (int i = 0; i < n - 2; i++)
            {
                arr[i] = i + 1;
            }
            vector<int> vec = Cantor::decode(k - 1, n - 2);
            cout << n << " " << 1;
            for (int i = 0; i < vec.size(); i++)
            {
                cout << " " << vec[i] + 1;
            }
            cout << endl;
        }
    }
    return 0;
}