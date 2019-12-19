#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node
{
    string s;
    int n, rank, rank2;
} arr[507];

int cmp(const Node &a, const Node &b)
{
    if (a.n == b.n)
    {
        return a.s < b.s;
    }
    else
    {
        return a.n > b.n;
    }
}

int main()
{
    int n;
    while (cin >> n && n)
    {
        for (int i = 1; i <= n; i++)
        {
            cin >> arr[i].s >> arr[i].n;
        }
        sort(arr + 1, arr + 1 + n, cmp);
        int r1 = 0, r2 = 0;
        for (int i = 1; i <= n; i++)
        {
            if (arr[i].n != arr[i - 1].n)
            {
                r1 = i;
                r2 = 1;
            }
            else
            {
                r2++;
            }
            arr[i].rank = r1;
            arr[i].rank2 = r2;
            cout << arr[i].s << ' ' << arr[i].n << endl;
        }
        int q;
        cin >> q;
        while (q--)
        {
            string s;
            cin >> s;
            for (int i = 1; i <= n; i++)
            {
                if (arr[i].s == s)
                {
                    cout << arr[i].rank;
                    if (arr[i].rank2 != 1)
                    {
                        cout << ' ' << arr[i].rank2;
                    }
                    break;
                }
            }
            cout << endl;
        }
    }
    return 0;
}