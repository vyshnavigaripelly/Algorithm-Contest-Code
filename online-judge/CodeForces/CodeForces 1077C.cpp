#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    int x, y;
} arr[200007];

int cmp(const Node &a, const Node &b)
{
    return a.y > b.y;
}

int main()
{
    vector<int> ans;
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        arr[i].x = i;
        cin >> arr[i].y;
        sum += arr[i].y;
    }
    sort(arr + 1, arr + 1 + n, cmp);
    if (sum - arr[1].y == 2 * arr[2].y)
    {
        ans.push_back(arr[1].x);
    }
    for (int i = 2; i <= n; i++)
    {
        if (sum - arr[i].y == 2 * arr[1].y)
        {
            ans.push_back(arr[i].x);
        }
    }
    cout << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << ' ';
    }
    return 0;
}