#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;

int nxt[N][101]; //nxt[i][j]表示第i位的下一个数j在哪个位置
vector<int> pos[101];
int endcnt[101], nowcnt[101]; //endcnt[i]存储数i的个数,nowcnt[i]表示当前扫过了第i个数的哪一个
int arr[N];

int main()
{
    int n, c;
    cin >> n >> c;
    memset(nxt, -1, sizeof(nxt));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &arr[i]);
        pos[arr[i]].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        nowcnt[arr[i]]++;
        for (int j = 1; j <= 100; j++)
        {
            if (pos[j].size() > nowcnt[j])
            {
                nxt[i][j] = pos[j][nowcnt[j]];
            }
        }
    }
    int ans = 0;
    for (int x = 1; x <= c; x++)
    {
        for (int y = 1; y <= c; y++)
        {
            if (x == y)
                continue;
            int len = 0, choice = 0;
            int nowpos = -1;
            if (pos[x].size())
            {
                nowpos = pos[x][0];
                while (nowpos != -1)
                {
                    nowpos = nxt[nowpos][choice ? x : y];
                    len++;
                    choice ^= 1;
                }
            }
            ans = max(ans, len);
        }
    }
    if (ans == 1)
        ans = 0;
    cout << ans << endl;
    return 0;
}