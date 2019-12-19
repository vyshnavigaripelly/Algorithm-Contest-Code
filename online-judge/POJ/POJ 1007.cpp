#include <algorithm>
#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

const int maxlen = 107;

struct Node
{
    string s;
    int idx, num;
} arr[107];

char brr[maxlen], temp[maxlen];
int sum;

int cmp(const Node &a, const Node &b)
{
    return a.num < b.num || (a.num == b.num && a.idx < b.idx);
}

void merge(int l, int r, int m)
{
    int i = l, j = m + 1, k = l;
    while (i <= m && j <= r)
    {
        if (brr[i] > brr[j])
        {
            sum += m - i + 1;
            temp[k++] = brr[j++];
        }
        else
        {
            temp[k++] = brr[i++];
        }
    }
    while (i <= m)
        temp[k++] = brr[i++];
    while (j <= r)
        temp[k++] = brr[j++];
    for (i = l; i <= r; i++)
        brr[i] = temp[i];
}

void mergesort(int l, int r)
{
    if (l < r)
    {
        int m = (l + r) / 2;
        mergesort(l, m);
        mergesort(m + 1, r);
        merge(l, r, m);
    }
}

int main()
{

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[i].s;
        arr[i].idx = i;
        for (int j = 0; j < n; j++)
        {
            brr[j] = arr[i].s[j];
        }
        sum = 0;
        mergesort(0, n - 1);
        arr[i].num = sum;
    }
    sort(arr, arr + m, cmp);
    for (int i = 0; i < m; i++)
    {
        cout << arr[i].s << endl;
    }
    return 0;
}