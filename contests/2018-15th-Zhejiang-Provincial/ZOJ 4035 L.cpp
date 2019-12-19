#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    string s;
    long long k; // 垃圾测试数据，说好的1e9为什么要用long long
};

int cmp(const Node &a, const Node &b)
{
    if (a.k != b.k)
    {
        return a.k > b.k;
    }
    else
    {
        return a.s < b.s;
    }
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        Node arr[105];
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].s >> arr[i].k;
        }
        sort(arr + 1, arr + n + 1, cmp);
        long long ans = 0;
        for (int i = 1; i <= m; i++)
        {
            ans += arr[i].k * (m - i + 1);
        }
        cout << ans;
        for (int i = 1; i <= m; i++)
        {
            cout << ' ' << arr[i].s;
        }
        cout << endl;
    }
    return 0;
}
