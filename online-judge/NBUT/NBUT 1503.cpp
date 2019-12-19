#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int b, f, m;
};

bool cmp(const Node &a, const Node &b)
{
    if (a.b != b.b)
    {
        return a.b > b.b;
    }
    else if (a.f != b.f)
    {
        return a.f > b.f;
    }
    else
    {
        return a.m > b.m;
    }
}

int main()
{
    int n;
    while (cin >> n)
    {
        Node arr[1100];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].b >> arr[i].f >> arr[i].m;
        }
        sort(arr, arr + n, cmp);
        cout << arr[0].b << ' ' << arr[0].f << ' ' << arr[0].m << endl;
    }
    return 0;
}
