#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int k, pos, flag;
} arr[2000];

int ans[2007];

int cmp(const Node &a, const Node &b)
{
    if (a.k != b.k)
    {
        return a.k > b.k;
    }
    else
    {
        return a.pos < b.pos;
    }
}

int cmp2(const Node &a, const Node &b)
{
    return a.pos < b.pos;
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i].k;
        arr[i].pos = i;
        arr[i].flag = 0;
    }
    sort(arr, arr + n, cmp);
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        arr[i].flag = 1;
        sum += arr[i].k;
    }
    sort(arr, arr + n, cmp2);
    int rest = n, prev = -1, cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].flag == 1)
        {
            ans[cnt++] = i - prev;
            rest -= (i - prev);
            prev = i;
        }
    }
    ans[cnt - 1] += rest;
    cout << sum << endl;
    for (int i = 0; i < cnt; i++)
    {
        cout << ans[i] << ' ';
    }
    return 0;
}