#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int idx, val;
};

int cmp(Node &a, Node &b)
{
    return a.val > b.val;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        Node arr[105];
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].val;
            arr[i].idx = i + 1;
        }
        sort(arr, arr + n, cmp);
        cout << arr[0].idx << ' ' << arr[1].val << endl;
    }
    return 0;
}
