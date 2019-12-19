#include <bits/stdc++.h>

using namespace std;

const long long mod = 1000000007;
const int N = 26;
const int MAXN = 3e5 + 7;

long long ans;

struct Palindromic_Tree
{
    // 节点0,1是根 不可用。
    vector<pair<int, int>> next[MAXN];
    int fail[MAXN]; //fail指针，失配后跳转到fail指针指向的节点
    long long cnt[MAXN]; //表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的)
    int len[MAXN]; //len[i]表示节点i表示的回文串的长度
    int S[MAXN]; //存放添加的字符

    int last; //指向上一个字符所在的节点，方便下一次add
    int n; //表示添加的字符个数。
    int p; //表示添加的节点个数。
    int pd[MAXN];
    long long lenth[MAXN];

    int newnode(int l) //新建节点
    {
        next[p].clear();
        len[p] = l;
        return p++;
    }

    void init() //初始化
    {
        memset(lenth, 0, sizeof lenth);
        memset(pd, 0, sizeof pd);
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1; //开头放一个字符集中没有的字符，减少特判
        fail[0] = 1;
    }

    int get_fail(int x) //和KMP一样，失配后找一个尽量最长的
    {
        while (S[n - len[x] - 1] != S[n])
            x = fail[x];
        return x;
    }

    int find(int u, int c)
    {
        vector<pair<int, int>> &x = next[u];
        int sz = x.size();
        for (int i = 0; i < sz; ++i)
        {
            if (x[i].first == c)
                return x[i].second;
        }
        return 0;
    }

    void add(int c)
    {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last); //通过上一个回文串找这个回文串的匹配位置
        int x = find(cur, c);
        if (!x) //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
        {

            int now = newnode(len[cur] + 2); //新建节点
            x = now;
            fail[now] = find(get_fail(fail[cur]), c); //和AC自动机一样建立fail指针，以便失配后跳转
            next[cur].push_back(make_pair(c, now));
            pd[now] = pd[cur];
            pd[now] |= (1 << c);
            if (pd[now] != pd[cur])
            {
                lenth[now] = lenth[cur] + 1;
            }
            else
            {
                lenth[now] = lenth[cur];
            }
            if (cur != 1)
            {
                ans += lenth[now];
            }
        }
        last = x;
        cnt[last]++;
    }

    void count()
    {
        for (int i = p - 1; i >= 0; --i)
            cnt[fail[i]] += cnt[i];
    }
};

Palindromic_Tree pam;

long long sum = 0;
string s;

int main()
{
    int T, ks = 0;
    cin >> s;
    pam.init();
    for (int i = 0; i < s.length(); i++)
    {
        pam.add(s[i]);
    }
    pam.count();
    ans = 0;
    for (int i = pam.p; i >= 2; i--)
    {
        ans += pam.cnt[i] * pam.lenth[i];
    }
    cout << ans << endl;
    return 0;
}
