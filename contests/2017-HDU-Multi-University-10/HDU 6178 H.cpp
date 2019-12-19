#include <iostream>
#include <vector>
#include <cstring>

#define N 100007
const int BUFSIZE = 20 << 21;

using namespace std;

int n, k, fa[N], used[N], cnt;
char Buf[BUFSIZE + 1], *buf = Buf;

template <class T>

void scan(T &a)
{
    for (a = 0; *buf < '0' || *buf > '9'; buf++)
        ;
    while (*buf >= '0' && *buf <= '9')
    {
        a = a * 10 + (*buf - '0');
        buf++;
    }
}

int main()
{
    fread(Buf, 1, BUFSIZE, stdin);
    int t;
    scan<int>(t);
    while (t--)
    {
        int v;
        cnt = 0;
        scan<int>(n);
        scan<int>(k);
        memset(used, 0, (n + 1) * sizeof(int));
        for (int i = 2; i <= n; i++)
        {
            scan<int>(v);
            fa[i] = v;
        }
        for (int i = n; i >= 2; i--)
        {
            if (!used[i] && !used[fa[i]])
            {
                used[i] = 1;
                used[fa[i]] = 1;
                cnt++;
            }
        }
        int ans;
        if (2 * cnt >= k)
            ans = (k + 1) / 2;
        else
            ans = k - cnt;
        printf("%d\n", ans);
    }
    return 0;
}