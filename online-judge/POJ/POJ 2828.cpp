#include <iostream>
#include <cstring>

using namespace std;

const int N = 2e5 + 7;

int pos[N], val[N], tree[N], ans[N];

int ask(int x)
{
    int ans = 0;
    for (; x; x -= (x & -x))
        ans += tree[x];
    return ans;
}

void add(int pos, int x)
{
    for (; pos <= N; pos += (pos & -pos))
        tree[pos] += x;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    while (cin >> n)
    {
        memset(tree, 0, sizeof(tree));
        for (int i = 1; i <= n; i++)
        {
            cin >> pos[i] >> val[i];
            add(i, 1);
        }
        for (int i = n; i >= 1; i--)
        {
            int l = 1, r = n;
            while (l < r)
            {
                int mid = (l + r) >> 1;
                if (ask(mid) < pos[i] + 1)
                {
                    l = mid + 1;
                }
                else
                {
                    r = mid;
                }
            }
            add(l, -1);
            ans[l] = val[i];
        }
        for (int i = 1; i <= n; i++)
        {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}