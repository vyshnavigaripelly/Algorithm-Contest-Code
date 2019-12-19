#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node
{
    int j;
    int f;
    double k;
} arr[1010];

bool cmp(Node &a, Node &b)
{
    return a.k > b.k;
}

int main()
{
    int m, n;
    while (cin >> m >> n && m != -1 && n != -1)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].j >> arr[i].f;
            arr[i].k = 1.0 * arr[i].j / arr[i].f;
        }
        sort(arr, arr + n, cmp);
        double s = 0;
        for (int i = 0; i < n; i++)
        {
            if (m > arr[i].f)
            {
                m -= arr[i].f;
                s += arr[i].j;
            }
            else
            {
                s += m * arr[i].k;
                break;
            }
        }
        printf("%.3lf\n", s);
    }
    return 0;
}
