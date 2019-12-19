#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node
{
    int h, idx;
};

int cmph(const Node &a, const Node &b)
{
    return a.h < b.h;
}

int cmpidx(const Node &a, const Node &b)
{
    return a.idx < b.idx;
}
int main()
{
    int n, k;
    cin >> n;
    vector<Node> arr(n + 2);
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i].h;
        arr[i].idx = i;
    }
    sort(arr.begin() + 1, arr.begin() + 1 + n, cmph);
    for (int i = 1; i <= n; i++)
    {
        arr[i].h = i;
    }
    sort(arr.begin() + 1, arr.begin() + 1 + n, cmpidx);
    for (int cur = 1; cur <= n; cur++)
    {
        int pos = -1;
        for (int i = cur; i <= n; i++)
        {
            if (arr[i].h == cur)
            {
                pos = i;
                break;
            }
        }
        for (int j = pos - 1; j >= cur; j--)
        {
            cout << j << ' ' << j + 1 << endl;
        }
        arr.erase(arr.begin() + pos);
        arr.insert(arr.begin(), {0, 0});
    }
    return 0;
}