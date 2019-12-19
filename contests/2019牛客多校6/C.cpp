#include <bits/stdc++.h>

using namespace std;

const int MAXN = 300010;
const int N = 28;

long long pow_m(long long a, long long b, long long mod)
{
    long long res = 1;
    a = a % mod;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

struct Palindromic_Tree
{
    // 节点0,1是根 不可用。
    int next[MAXN][N]; //next指针，next指针和字典树类似，指向的串为当前串两端加上同一个字符构成
    int fail[MAXN]; //fail指针，失配后跳转到fail指针指向的节点
    int cnt[MAXN]; //表示节点i表示的本质不同的串的个数（建树时求出的不是完全的，最后count()函数跑一遍以后才是正确的)
    int num[MAXN]; //表示以节点i表示的最长回文串的最右端点为回文串结尾的回文串个数
    int len[MAXN]; //len[i]表示节点i表示的回文串的长度
    int S[MAXN]; //存放添加的字符
    int last; //指向上一个字符所在的节点，方便下一次add
    int n; //表示添加的字符个数。
    int p; //表示添加的节点个数。
    int vis[MAXN];
    long long ans;

    int newnode(int l) //新建节点
    {
        for (int i = 0; i < N; ++i)
            next[p][i] = 0, vis[i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        return p++;
    }

    void init()
    { //初始化
        p = 0;
        ans = 0;
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

    void add(int c)
    {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last); // 通过上一个回文串找这个回文串的匹配位置
        if (!next[cur][c])
        { //如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int now = newnode(len[cur] + 2); //新建节点
            fail[now] = next[get_fail(fail[cur])][c]; //和AC自动机一样建立fail指针，以便失配后跳转
            next[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = next[cur][c];
        cnt[last]++;
    }

    void count()
    {
        for (int i = p - 1; i >= 0; --i)
            cnt[fail[i]] += cnt[i];
    }

    void dfs(int u, int s)
    {
        vector<int> vec;
        for (int i = fail[u]; i >= 1; i = fail[i])
        {
            if (vis[i] == 1)
                break;
            s++;
            vis[i] = 1;
            vec.push_back(i);
        }
        ans += s;
        if (vis[u] == 0)
        {
            vis[u] = 1;
            s++;
        }
        for (int i = 0; i < 26; i++)
        {
            if (next[u][i])
                dfs(next[u][i], s);
        }
        if (u != 0 && u != 1)
            vis[u] = 0;
        for (int i = 0; i < vec.size(); i++)
            vis[vec[i]] = 0;
    }

    void work()
    {
        vis[0] = 1;
        vis[1] = 1;
        dfs(0, 0);
        dfs(1, 0);
    }
};

Palindromic_Tree pam;

int main()
{
    int t, cas = 0;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        pam.init();
        for (int i = 0; i < s.length(); i++)
        {
            pam.add(s[i]);
        }
        pam.work();
        cout << "Case #" << ++cas << ": " << pam.ans << endl;
    }
    return 0;
}