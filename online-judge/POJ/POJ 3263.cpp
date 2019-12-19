#include <iostream>
#include <map>

using namespace std;

map<pair<int, int>, int> vis;

int height[100007];

int main()
{
    int n, idx, h, r;
    cin >> n >> idx >> h >> r;
    while (r--)
    {
        int a, b;
        cin >> a >> b;
        if (a > b)
        {
            swap(a, b);
        }
        if (vis[make_pair(a, b)])
        {
            continue;
        }
        height[a + 1]--;
        height[b]++;
        vis[make_pair(a, b)] = 1;
    }
    for (int i = 2; i <= n; i++)
    {
        height[i] += height[i - 1];
    }
    for (int i = 1; i <= n; i++)
    {
        cout << h + height[i] << endl;
    }
    return 0;
}