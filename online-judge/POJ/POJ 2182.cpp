#include <iostream>

using namespace std;

const int N = 1e4 + 7;

int arr[N], tree[N], ans[N];

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
    int n;
    cin >> n;
    arr[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        cin >> arr[i];
        arr[i]++;
    }
    for (int i = 1; i <= n; i++)
    {
        add(i, 1);
    }
    for (int i = n; i >= 1; i--)
    {
        int l = 1, r = n;
        while (l < r)
        {
            int mid = (l + r) >> 1;
            if (ask(mid) < arr[i])
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        add(l, -1);
        ans[i] = l;
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}