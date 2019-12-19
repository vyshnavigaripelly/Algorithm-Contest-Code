#include <iostream>
#include <algorithm>
using namespace std;

int dp[300][300];

struct Node
{
    int a, b;
};

bool cmp(Node &x, Node &y)
{
    return x.b < y.b;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        Node tree[300];
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> tree[i].a;
        }
        for (int i = 1; i <= n; i++)
        {
            cin >> tree[i].b;
        }
        sort(tree + 1, tree + n + 1, cmp);
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1] + tree[i].b * (j - 1) + tree[i].a);
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}
